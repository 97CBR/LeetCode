// 面试题 01.06. 字符串压缩
// 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

// 示例1:

//  输入："aabcccccaaa"
//  输出："a2b1c5a3"
// 示例2:

//  输入："abbccd"
//  输出："abbccd"
//  解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
// https : //leetcode-cn.com/problems/compress-string-lcci/

// 思路：
// 遍历一遍字符串，然后，保存当前的字符。往后遍历，没有更改的时候，计数加一，
// 如果有更改，则将其保存到当前字符，并计数器计为 1
// 并将之前计数完毕的那部分给 += 保存起来
// 然后再进行长度比较就好了

// 特别注意:这题告诉我们  a+=b 比  a= a+b 好

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
