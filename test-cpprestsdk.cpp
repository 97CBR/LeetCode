#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
// #include <iostream>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif
// #include <cpprest/http_client.h>
using namespace std;

int watch()
{
    HANDLE hDir;
    char notify[1024];
    DWORD cbBytes, i;
    char AnsiChar[3];
    wchar_t UnicodeChar[2];
    LPCSTR path = "E:\\";

    char *pnotify = new char[1024];
    PFILE_NOTIFY_INFORMATION tmp;

    // GetCurrentDirectory(MAX_PATH, path.GetBuffer(MAX_PATH + 1));

    hDir = CreateFile(path, FILE_LIST_DIRECTORY,
                      FILE_SHARE_READ |
                          FILE_SHARE_WRITE |
                          FILE_SHARE_DELETE,
                      NULL,
                      OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);
    if (hDir == INVALID_HANDLE_VALUE)
    {

        cout << "hDir:INVALID_HANDLE_VALUE\r\n"
             << endl;
        return 0;
    }

    while (TRUE)
    {
        if (ReadDirectoryChangesW(hDir, pnotify, sizeof(notify),
                                  true, FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_LAST_WRITE,
                                  &cbBytes, NULL, NULL))
        {

            tmp = (PFILE_NOTIFY_INFORMATION)pnotify;
            char fileBuffer[512];
            switch (tmp->Action)
            {
            case FILE_ACTION_ADDED:

                memset(&fileBuffer, 0, sizeof(fileBuffer));
                WideCharToMultiByte(CP_ACP, 0, tmp->FileName, tmp->FileNameLength / 2, fileBuffer, 1024, NULL, NULL);
                cout << "Directory/File added - \r\n"
                     << fileBuffer << endl;

                break;
            case FILE_ACTION_REMOVED:
                memset(&fileBuffer, 0, sizeof(fileBuffer));
                WideCharToMultiByte(CP_ACP, 0, tmp->FileName, tmp->FileNameLength / 2, fileBuffer, 1024, NULL, NULL);
                cout << "Directory/File removed - \r\n"
                     << fileBuffer << endl;
                break;
            case FILE_ACTION_MODIFIED:
                // cout << "Directory/File modified ���޸��ļ����ݣ�- \r\n"
                //  << tmp->FileName << endl;
                break;
            case FILE_ACTION_RENAMED_OLD_NAME:
                cout << "Directory/File old name ���޸��ļ����֣�- \r\n"
                     << tmp->FileName << endl;
                break;
            case FILE_ACTION_RENAMED_NEW_NAME:
                cout << "Directory/File new name - \r\n"
                     << tmp->FileName << endl;
                break;
            default:
                break;
            }
        }
    }
}

int main()
{
    watch();
    // //����C�̸�Ŀ¼���ļ����ı�����ӣ�����whileѭ��һֱ��أ�ֱ������ر�
    // HANDLE hChangeHandle = FindFirstChangeNotification("D:\\", true, FILE_NOTIFY_CHANGE_FILE_NAME);
    // //�ж��Ƿ����óɹ�
    // if (hChangeHandle == INVALID_HANDLE_VALUE)
    // {
    //     printf("Find First Change Notification failed\n");
    //     ExitProcess(GetLastError());
    //     return 0;
    // }
    // //�ȴ�֪ͨ
    // printf("These change a file name\n");
    // //ѭ���ȴ�
    // while (true)
    //     if (FindNextChangeNotification(hChangeHandle))
    //     {
    //         printf("These change a file name\n");
    //         //�������ӳ������FindCloseChangeNotification�رվ��
    //     }
    // FindCloseChangeNotification(hChangeHandle);
    // getch(); //�����˳�����
}
// #include <iostream>
// #ifdef _WIN32
// #include <fcntl.h>
// #include <io.h>
// #endif
// #include <cpprest/http_client.h>

// using namespace utility;
// using namespace web::http;
// using namespace web::http::client;
// using std::cerr;
// using std::endl;

// #ifdef _WIN32
// #define tcout std::wcout
// #else
// #define tcout std::cout
// #endif

// auto get_headers(http_response resp)
// {
//     auto headers = resp.to_string();
//     auto end =
//         headers.find(U("\r\n\r\n"));
//     if (end != string_t::npos)
//     {
//         headers.resize(end + 4);
//     };
//     return headers;
// }

// auto get_request(string_t uri)
// {
//     http_client client{uri};
//     // �� GET ��ʽ����һ���ͻ�������
//     auto request =
//         client.request(methods::GET)
//             .then([](http_response resp) {
//                 if (resp.status_code() !=
//                     status_codes::OK)
//                 {
//                     // �� OK����ʾ��ǰ��Ӧ��Ϣ
//                     auto headers =
//                         get_headers(resp);
//                     tcout << headers;
//                 }
//                 // ��һ��ȡ��������Ӧ
//                 return resp
//                     .extract_string();
//             })
//             .then([](string_t str) {
//                 // ������ն�
//                 tcout << str;
//             });
//     return request;
// }

// #ifdef _WIN32
// int wmain(int argc, wchar_t *argv[])
// #else
// int main(int argc, char *argv[])
// #endif
// {
// #ifdef _WIN32
//     _setmode(_fileno(stdout),
//              _O_WTEXT);
// #endif

//     if (argc != 2)
//     {
//         cerr << "A URL is needed\n";
//         return 1;
//     }

//     // �ȴ��������������ȫ�����
//     try
//     {
//         auto request =
//             get_request(argv[1]);
//         request.wait();
//     }
//     // ������������в������쳣
//     catch (const std::exception &e)
//     {
//         cerr << "Error exception: "
//              << e.what() << endl;
//         return 1;
//     }
// }