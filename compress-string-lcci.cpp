// ������ 01.06. �ַ���ѹ��
// �ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ���aabcccccaaa���Ϊa2b1c5a3������ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���������Լ����ַ�����ֻ������СдӢ����ĸ��a��z����

// ʾ��1:

//  ���룺"aabcccccaaa"
//  �����"a2b1c5a3"
// ʾ��2:

//  ���룺"abbccd"
//  �����"abbccd"
//  ���ͣ�"abbccd"ѹ����Ϊ"a1b2c2d1"����ԭ�ַ������ȸ�����
// https : //leetcode-cn.com/problems/compress-string-lcci/

// ˼·��
// ����һ���ַ�����Ȼ�󣬱��浱ǰ���ַ������������û�и��ĵ�ʱ�򣬼�����һ��
// ����и��ģ����䱣�浽��ǰ�ַ�������������Ϊ 1
// ����֮ǰ������ϵ��ǲ��ָ� += ��������
// Ȼ���ٽ��г��ȱȽϾͺ���

// �ر�ע��:�����������  a+=b ��  a= a+b ��

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
    string compressString(string S)
    {
        // string old_str = S;
        S += " ";
        char my_char = '\0';
        int c = 0;
        string res_str = "";
        int flag = 0;
        char now_char = '\0';
        for (int i = 0; i < S.length(); i++)
        {
            now_char = S.at(i);
            if (my_char == now_char)
            {
                c += 1;
                // cout << my_char << c << endl;
                // cout << "not change " << my_char << c << endl;
            }
            else
            {
                if (!flag)
                {
                    my_char = now_char;
                    c = 1;
                    flag = 1;
                    continue;
                }

                res_str +=  my_char + to_string(c);

                // S.replace(i, c, my_char + to_string(c));

                my_char = now_char;
                c = 1;

                // cout << "change " << my_char << c << endl;
                flag = 1;
            }
        }
        return res_str.length() < S.length() - 1 ? res_str : S.substr(0, S.length() - 1);
        // if (res_str.length() < S.length() - 1)
        // {
        //     cout << res_str << endl;
        //     return res_str;
        // }
        // else
        // {
        //     cout << S.substr(0, S.length() - 1) << endl;
        //     return S.substr(0, S.length() - 1);
        // }
    }
};

int main()
{
    cout << "Hello" << endl;

    string target = "aabcccccaaa";

    // string target = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";

    Solution cbr;
    cout <<cbr.compressString(target)<< endl;

    return 0;
}
