// 西山居笔试题 第一题，
// 寻找字符串串中，第一个重复的字母
//请注意，细品一下  第一个重复的字母 的意思
//例如：
// input：wuhanjiayoutt
// output： a

// 思路：
// 遍历字符串，寻找其字符，最左边的，和最右边的 index
// 然后 如果两个index不同，就进行下一步
// 如果其index长度距离比原来记录的短，就记下这个字符
// 遍历字符串的最右的位置，由最新记录的字符的 右边 index 进行控制。初始化为最右

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
