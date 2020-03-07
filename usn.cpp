/**
* ��Ntfs��USN������ʾ������
*/
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <time.h>
#include <winternl.h>
#include <winbase.h>
#include <vector>
#include <algorithm>

using namespace std;

#define BUF_LEN 4096

ofstream fout("E:\\log.txt");
long counter = 0;

vector<DWORDLONG> G_element_node;

//���Ƚ��к������͵Ķ���

typedef NTSTATUS(NTAPI *NTCREATEFILE)(
	OUT PHANDLE FileHandle,
	IN ACCESS_MASK DesiredAccess,
	IN POBJECT_ATTRIBUTES ObjectAttributes,
	OUT PIO_STATUS_BLOCK IoStatusBlock,
	IN PLARGE_INTEGER AllocationSize OPTIONAL,
	IN ULONG FileAttributes,
	IN ULONG ShareAccess,
	IN ULONG CreateDisposition,
	IN ULONG CreateOptions,
	IN PVOID EaBuffer OPTIONAL,
	IN ULONG EaLength);

typedef NTSTATUS(NTAPI *NTQUERYINFORMATIONFILE)(
	HANDLE handle,
	PIO_STATUS_BLOCK io,
	PVOID ptr,
	ULONG len,
	FILE_INFORMATION_CLASS FileInformationClass);

typedef NTSTATUS(NTAPI *NTCLOSE)(

	IN HANDLE Handle);



int file_type(char *patName, char *relName)
{
	string pat;
	string allname;
	pat = patName;
	allname = relName;
	int flag = 0;
	string temp[] = {".exe",
					 ".cpp",
					 ".zip",
					 ".css"};
	for (int i = 0; i < sizeof(temp) / sizeof(string); i++)
	{
		// cout << temp[i] << endl;
		int f_i = allname.find(temp[i], allname.length() - temp[i].length() - 1);
		if (f_i != allname.npos)
		{
			flag = 1;
		}
	}

	// cout << flag <<endl;
	// int index = allname.find(pat, allname.length() - pat.length() - 1);
	// if (index != allname.npos)
	// 	flag = 1;
	// else
	// 	return 0;
	return flag;
}

HMODULE load_ntdll(HMODULE hmodule)
{
	LPCSTR MYDLL = "ntdll.dll";
	hmodule = LoadLibrary(MYDLL);
	if (!hmodule)
		cout << "����ntdll.dllʧ��" << endl
			 << endl;
	return hmodule;
}

//volume_handleΪʹ��CreateFile��õľ���
void get_path_from_frn(HANDLE &volume_handle, DWORDLONG frn)
{
	//Nt�����ĵ���

	HMODULE hmodule = NULL;

	hmodule = load_ntdll(hmodule);

	NTCREATEFILE NtCreateFile = NULL;
	NtCreateFile = (NTCREATEFILE)GetProcAddress(hmodule, "NtCreateFile");
	if (!NtCreateFile)
		cout << "����NtCreateFile����ʧ��" << endl
			 << endl;

	NTQUERYINFORMATIONFILE NtQueryInformationFile = NULL;
	NtQueryInformationFile = (NTQUERYINFORMATIONFILE)GetProcAddress(hmodule, "NtQueryInformationFile");
	if (!NtQueryInformationFile)
		cout << "����NtQueryInformationFile����ʧ��" << endl
			 << endl;

	NTCLOSE NtClose = NULL;
	NtClose = (NTCLOSE)GetProcAddress(hmodule, "NtClose");
	if (!NtClose)
		cout << "����NtClose����ʧ��" << endl
			 << endl;

	//������������Ķ���

	UNICODE_STRING us_id; //UNICODE_STRING�͵��ļ�ID
	OBJECT_ATTRIBUTES oa;
	IO_STATUS_BLOCK isb;
	LARGE_INTEGER id;		   //�ļ�ID
	HANDLE file_handle = NULL; //frn��ָʾ���ļ��ľ��

	id.QuadPart = frn; //�ļ�ID��ֵΪfrn

	us_id.Buffer = (WCHAR *)&id; //����UNICODE�͵��ļ�ID
	us_id.Length = 8;
	us_id.MaximumLength = 8;

	oa.ObjectName = &us_id; //��ֵOBJECT_ATTRIBUTES�ṹ��
	oa.Length = sizeof(OBJECT_ATTRIBUTES);
	oa.RootDirectory = volume_handle;
	oa.Attributes = OBJ_CASE_INSENSITIVE;
	oa.SecurityDescriptor = NULL;
	oa.SecurityQualityOfService = NULL;

	//ʹ��NtCreateFile����ͨ���ļ�ID���Ŀ���ļ��ľ��

	ULONG status = NtCreateFile(
		&file_handle,
		FILE_GENERIC_READ,
		&oa,
		&isb,
		NULL,
		FILE_ATTRIBUTE_NORMAL,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		FILE_OPEN,
		FILE_OPEN_BY_FILE_ID,
		NULL,
		0);

	if (0 == status)
	{
		FILE_NAME_INFORMATION *name_info = (FILE_NAME_INFORMATION *)malloc(512);

		//���øոյõ��ľ��ͨ��NtQueryInformationFile�������·����Ϣ

		status = NtQueryInformationFile(
			file_handle,
			&isb,
			name_info,
			512,
			FileNameInformation);

		if (0 == status)
		{
			char path_buf[260] = {0};
			int path_size = (*name_info).FileNameLength;
			//���ַ�תΪchar��
			WideCharToMultiByte(CP_OEMCP, 0, (*name_info).FileName, path_size / 2, path_buf, path_size, NULL, NULL);
			cout << "·����"
				 << "w:" << path_buf << endl
				 << endl;
		}

		free(name_info);
		NtClose(file_handle); //�ر�Ŀ���ļ����
	}

	// CloseHandle(volume_handle);//�رվ���
}

void watch_usn(char *volName, HANDLE hVol, USN_JOURNAL_DATA UsnInfo)
{
	BOOL status;
	BOOL isNTFS = false;
	BOOL getHandleSuccess = false;
	BOOL initUsnJournalSuccess = false;

	//�ж��������Ƿ�NTFS��ʽ
	// cout << "step 01. nstf �ж��������Ƿ�NTFS��ʽ\n";
	cout << "step 01. nstf \n";
	char sysNameBuf[MAX_PATH] = {0};
	status = GetVolumeInformationA(volName,
								   NULL,
								   0,
								   NULL,
								   NULL,
								   NULL,
								   sysNameBuf, // �����̵�ϵͳ��
								   MAX_PATH);
	cout << status << endl;
	if (0 != status)
	{
		cout << "file system:" << sysNameBuf << "\n";
		// �Ƚ��ַ���
		if (0 == strcmp(sysNameBuf, "NTFS"))
		{
			// cout << "����������NTFS��ʽ��ת��step-02.\n";
			cout << "step-02.\n";
			isNTFS = true;
		}
		else
		{
			cout << "�������̷�NTFS��ʽ\n";
		}
	}

	if (isNTFS)
	{
		//step 02. ��ȡ�����̾��
		cout << "step 02. get handel \n";
		char fileName[MAX_PATH];
		fileName[0] = '\0';
		strcpy_s(fileName, "\\\\.\\"); //������ļ���
		strcat_s(fileName, volName);
		string fileNameStr = (string)fileName;
		fileNameStr.erase(fileNameStr.find_last_of(":") + 1);
		cout << "�����̵�ַ:" << fileNameStr.data() << "\n";

		hVol = CreateFileA(fileNameStr.data(), //�ɴ򿪻򴴽����¶��󣬲����ؿɷ��ʵľ��������̨��ͨ����Դ��Ŀ¼��ֻ���򿪣����������������ļ�
						   GENERIC_READ | GENERIC_WRITE,
						   FILE_SHARE_READ | FILE_SHARE_WRITE,
						   NULL,
						   OPEN_EXISTING,
						   FILE_ATTRIBUTE_READONLY,
						   NULL);
		cout << hVol << endl;

		if (INVALID_HANDLE_VALUE != hVol)
		{
			cout << "��ȡ�����̾���ɹ���ת��step-03.\n";
			getHandleSuccess = true;
		}
		else
		{
			cout << "��ȡ�����̾��ʧ�� ���� handle:" << hVol << " error:" << GetLastError() << "\n";
		}
	}

	if (getHandleSuccess)
	{
		//step 03. ��ʼ��USN��־�ļ�
		cout << "step 03. ��ʼ��USN��־�ļ�\n";
		DWORD br;
		CREATE_USN_JOURNAL_DATA cujd;
		cujd.MaximumSize = 0;
		cujd.AllocationDelta = 0;
		status = DeviceIoControl(hVol,
								 FSCTL_CREATE_USN_JOURNAL,
								 &cujd,
								 sizeof(cujd),
								 NULL,
								 0,
								 &br,
								 NULL);

		if (0 != status)
		{
			cout << "��ʼ��USN��־�ļ��ɹ���ת��step-04.\n";
			initUsnJournalSuccess = true;
		}
		else
		{
			cout << "��ʼ��USN��־�ļ�ʧ�� ���� status:" << status << " error:" << GetLastError() << "\n";
		}
	}

	if (initUsnJournalSuccess)
	{

		BOOL getBasicInfoSuccess = false;

		//step 04. ��ȡUSN��־������Ϣ(���ں�������)
		cout << "step 04. ��ȡUSN��־������Ϣ(���ں�������)\n";
		DWORD br;
		status = DeviceIoControl(hVol,
								 FSCTL_QUERY_USN_JOURNAL,
								 NULL,
								 0,
								 &UsnInfo,
								 sizeof(USN_JOURNAL_DATA),
								 &br,
								 NULL);

		if (0 != status)
		{
			cout << "��ȡUSN��־������Ϣ�ɹ���ת��step-05.\n";
			getBasicInfoSuccess = true;
		}
		else
		{
			cout << "��ȡUSN��־������Ϣʧ�� ���� status:" << status << " error:" << GetLastError() << "\n";
		}
		if (getBasicInfoSuccess)
		{
			cout << "UsnJournalID: " << UsnInfo.UsnJournalID << "\n";
			cout << "lowUsn: " << UsnInfo.FirstUsn << "\n";
			cout << "highUsn: " << UsnInfo.NextUsn << "\n";

			//step 05. ö��USN��־�ļ��е����м�¼
			cout << "step 05. ö��USN��־�ļ��е����м�¼\n";
			MFT_ENUM_DATA med;
			med.StartFileReferenceNumber = 0;
			med.LowUsn = 0;
			med.HighUsn = UsnInfo.NextUsn;

			CHAR buffer[BUF_LEN]; //�����¼�Ļ���,�����㹻�ش� buf_len = 4096
			DWORD usnDataSize;
			PUSN_RECORD UsnRecord;
			long clock_start = clock();

			vector<DWORDLONG> element_node;
			vector<DWORDLONG> tmp_vector;
			while (0 != DeviceIoControl(hVol,
										FSCTL_ENUM_USN_DATA,
										&med,
										sizeof(med),
										buffer,
										BUF_LEN,
										&usnDataSize,
										NULL))
			{
				DWORD dwRetBytes = usnDataSize - sizeof(USN);

				UsnRecord = (PUSN_RECORD)(((PCHAR)buffer) + sizeof(USN)); // �ҵ���һ��USN��¼
				while (dwRetBytes > 0)
				{
					const int strLen = UsnRecord->FileNameLength;
					char fileName[MAX_PATH] = {0};
					//char filePath[MAX_PATH] = {0};
					WideCharToMultiByte(CP_OEMCP, NULL, UsnRecord->FileName, strLen / 2, fileName, strLen, NULL, FALSE);

					//cout << "FileName: " << fileName << "\n";
					//cout << "FileReferenceNumber: " << UsnRecord->FileReferenceNumber << "\n";
					//cout << "ParentFileReferenceNumber: " << UsnRecord->ParentFileReferenceNumber << "\n";
					////cout<< "FilePath: " << filePath << "\n\n";
					if (file_type(".cpp", fileName))
					{

						element_node.push_back(UsnRecord->FileReferenceNumber);

						// ��ȡ�ļ�·��
						// get_path_from_frn(hVol, UsnRecord->FileReferenceNumber);

						fout << "FileName:" << fileName << endl;
						fout << "file type" << UsnRecord->FileAttributes << endl;
						fout << "FileReferenceNumber:" << UsnRecord->FileReferenceNumber << endl;
						fout << "ParentFileReferenceNumber:" << UsnRecord->ParentFileReferenceNumber << endl;
						fout << endl;
						counter++;
					}

					//fout << "FilePath:" << filePath << endl;

					// ��ȡ��һ����¼
					DWORD recordLen = UsnRecord->RecordLength;
					dwRetBytes -= recordLen;
					UsnRecord = (PUSN_RECORD)(((PCHAR)UsnRecord) + recordLen);
				}
				med.StartFileReferenceNumber = *(USN *)&buffer;
			}

			std::sort(element_node.begin(), element_node.end());
			tmp_vector = element_node;
			cout << "��" << counter << "���ļ�\n";

			if (G_element_node.size() == 0)
			{
				G_element_node = element_node;
				G_element_node.erase(G_element_node.begin() + 2345);
			}
			int gn = G_element_node.size();
			int sn = element_node.size();
			if (gn != sn)
			{
				cout << "�ļ��б�� �����Ϊ:" << sn - gn << endl;
				vector<DWORDLONG> change_file_node;

				for (int index = 0; index < G_element_node.size(); index++)
				{
					if (G_element_node.at(index) != tmp_vector.at(index))
					{
						change_file_node.push_back(tmp_vector.at(index));
						tmp_vector.erase(tmp_vector.begin() + index);
					}
				}
				while (G_element_node.size() != tmp_vector.size())
				{

					change_file_node.push_back(tmp_vector.at(tmp_vector.size() - 1));
					tmp_vector.erase(tmp_vector.end() - 1);
				}
				cout << "num" << change_file_node.size() << endl;

				for (int i = 0; i < change_file_node.size(); i++)
				{
					cout << change_file_node.at(i) << endl;
					get_path_from_frn(hVol, change_file_node.at(i));
				}
			}
			G_element_node = element_node;
			long clock_end = clock();
			cout << "����" << clock_end - clock_start << "����" << endl;
			fout << "��" << counter << "���ļ�" << endl;
			fout << flush;
			fout.close();
		}

		//step 06. ɾ��USN��־�ļ�(��ȻҲ���Բ�ɾ��)
		cout << "step 06. ɾ��USN��־�ļ�(��ȻҲ���Բ�ɾ��)\n";
		DELETE_USN_JOURNAL_DATA dujd;
		dujd.UsnJournalID = UsnInfo.UsnJournalID;
		dujd.DeleteFlags = USN_DELETE_FLAG_DELETE;

		status = 0;
		status = DeviceIoControl(hVol,
								 FSCTL_DELETE_USN_JOURNAL,
								 &dujd,
								 sizeof(dujd),
								 NULL,
								 0,
								 &br,
								 NULL);

		if (0 != status)
		{
			cout << "�ɹ�ɾ��USN��־�ļ�!\n";
		}
		else
		{
			cout << "ɾ��USN��־�ļ�ʧ�� ���� status:" << status << " error:" << GetLastError() << "\n";
		}
	}
	if (getHandleSuccess)
	{
		CloseHandle(hVol);
	} //�ͷ���Դ
}

int main()
{
	char *volName = "w:\\";
	// memset(volName, 0, sizeof(volName)/sizeof(char *));
	HANDLE hVol;
	USN_JOURNAL_DATA UsnInfo; // ����USN��־�Ļ�����Ϣ
	watch_usn(volName, hVol, UsnInfo);
	// Sleep(10000);
	// char *dv = "d:\\";
	// watch_usn(dv, hVol, UsnInfo);

	// while (1)
	// {

	// 	// watch_usn();
	// }
	//MessageBox(0, L"��ȷ���˳�", L"����", MB_OK);
	// getchar();
	return 0;
}