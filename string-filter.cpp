// ��ɽ�ӱ����� �ڶ��⣬
// ��������ɾ�� ģʽ���г��ֹ��������ַ�
// ���磺
// input��welcome to amazing seasun
// output��lom to mzing ssun

// ˼·��
// ����ģʽ����ÿ����һ��ģʽ���е��ַ�������������Ѱ�ң�Ȼ������replace�滻����
// ֱ��Ѱ�Ҳ���ģʽ���е��ַ�

#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string stringFilter(string strSrc, string strPat)
    {
        string tmp = strSrc;
        for (int i = 0; i < strPat.length(); i++)
        {
            while (tmp.find_last_of(strPat.at(i)) != tmp.npos)
            {
                tmp.replace(tmp.find_last_of(strPat.at(i)), 1, "");
            }
        }
        cout << tmp << endl;
        return tmp;
    }
};

int main()
{
    cout << "Hello" << endl;

    int nums[] = {2, 3, 1, 0, 2, 5, 3};
    string target = "welcome to amazing seasun";
    string duplication = "waecdf";
    Solution cbr;
    cbr.stringFilter(target, duplication);
    return 0;
}
