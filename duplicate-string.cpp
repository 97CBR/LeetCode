// ��ɽ�ӱ����� ��һ�⣬
// Ѱ���ַ������У���һ���ظ�����ĸ
//��ע�⣬ϸƷһ��  ��һ���ظ�����ĸ ����˼
//���磺
// input��wuhanjiayoutt
// output�� a

// ˼·��
// �����ַ�����Ѱ�����ַ�������ߵģ������ұߵ� index
// Ȼ�� �������index��ͬ���ͽ�����һ��
// �����index���Ⱦ����ԭ����¼�Ķ̣��ͼ�������ַ�
// �����ַ��������ҵ�λ�ã������¼�¼���ַ��� �ұ� index ���п��ơ���ʼ��Ϊ����

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
    char getFirstRepeatChar(string strSrc)
    {
        if (strSrc.length() <= 1)
        {
            return '\0';
        }
        string tmp = strSrc;
        char res = '\0';
        int len = 100000;
        string gg = tmp;
        int end_i = strSrc.length();

        for (int i = 0; i < end_i; i++)
        {

            int index_l = gg.find_first_of(strSrc[i]);
            int index_r = gg.find_last_of(strSrc[i]);
            if (index_l != index_r)
            {
                gg.replace(index_l, 1, "#");
                index_r = gg.find_first_of(strSrc[i]);
                cout << index_r - index_l << "\t" << strSrc[i] << endl;
                if ((index_r - index_l) < len)
                {
                    len = index_r - index_l;
                    res = strSrc[i];
                    end_i = index_r;
                }
            }
            else
            {
                continue;
            }
        }
        cout << res << endl;
        return res;
    }
};

int main()
{
    cout << "Hello" << endl;

    int nums[] = {2, 3, 1, 0, 2, 5, 3};
    string target = "wuhanjiayoutt";
    int duplication;
    Solution cbr;
    cbr.getFirstRepeatChar(target);
    return 0;
}
