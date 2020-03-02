#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>

using namespace std;

class Solution
{

private:
    int flag;
    int symbol;
    int res;

public:
    char *get_number_char(string str, char *tmp, int len)
    {
        // flag = 0;
        // char tmp[12];
        // cout << tmp << endl;
        memset(tmp, 0, sizeof(tmp));
        int j = 0;
        int bf = 0;
        int sf = 0;
        int cf = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                if (('0' <= str[i] && '9' >= str[i]) || '-' == str[i] || '+' == str[i])
                {
                    bf = 1;
                    cf = 0;
                    if ('0' <= str[i] && '9' >= str[i])
                    {
                        tmp[j] = str[i];
                        j += 1;
                        sf = 1;
                    }
                    else if ('-' == str[i] || '+' == str[i])
                    {

                        if (sf)
                        {
                            break;
                        }
                        else
                        {
                            tmp[j] = str[i];
                            j += 1;
                        }
                    }
                }
                else if (bf)
                {
                    break;
                }
                if (cf)
                {
                    break;
                }
            }
            else if (str[i] == ' ')
            {

                if (bf)
                {
                    break;
                }
                cf = 1;
                continue;
            }
        }
        for (; j < len; j++)
        {
            tmp[j] = '\000';
        }

        cout << tmp << endl;
        return tmp;
    }

    void ensure_pom(char c, char s)
    {
        if (c == '-')
        {
            if ('0' <= s && '9' >= s)
            {
                flag = 0;
                symbol = 1;
            }
            else
            {
                res = 0;
            }
        }
        else if (c == '+')
        {
            if ('0' <= s && '9' >= s)
            {
                flag = 1;
                symbol = 1;
            }
            else
            {
                res = 0;
            }
        }
        else
        {
            flag = 1;
            symbol = 0;
        }
        if (flag)
        {
            cout << "+" << endl;
        }
        else
        {
            cout << "-" << endl;
        }
    }

    char *take_out_zero(char *tmp, int len)
    {
        int i = 0;

        while (tmp[0] == '0')
        {
            tmp = tmp + 1;
            i += 1;
        }
        for (; i < len; i++)
        {
            tmp[i + 1] - '\000';
        }
        cout << tmp << endl;
        return tmp;
    }

    int myAtoi(string str)
    {
        int arl = 512;
        cout << str << endl;
        res = 1;
        char *num_char = new char[arl];
        memset(num_char, 0, sizeof(num_char));

        if (('0' <= str[0] && '9' >= str[0]) || '-' == str[0] || '+' == str[0] || ' ' == str[0])
        {

            num_char = get_number_char(str, num_char, arl);
            cout << num_char << endl;
            ensure_pom(num_char[0], num_char[1]);
            num_char = take_out_zero(num_char, arl);
            cout << "dsf" << num_char << endl;
            if (!res)
            {
                cout << res << endl;
                return res;
            }

            // char *tmp = new char[20];
            if (symbol)
            {
                // tmp = num_char + 1;
                num_char = num_char + 1;
            }
            cout << num_char << endl;
            string tmp = num_char;
            double num = 0;
            int len = tmp.length();
            for (int i = 0; i < len; i++)
            {
                num = num * 10 + (tmp[i] - '0');
            }
            cout << "res" << num << endl;
            if (flag)
            {
                cout << "+" << endl;

                if (num >= 2147483648)
                {
                    cout << "biger" << endl;
                    cout << "2147483647" << endl;
                    return 2147483647;
                }
                else
                {
                    cout << num << endl;
                    return (int)num;
                }
            }
            else
            {
                cout << "-" << endl;
                if (num >= 2147483648)
                {
                    cout << "minxer" << endl;
                    cout << "-2147483648" << endl;
                    return -2147483648;
                }
                else
                {
                    cout << "-" << num << endl;
                    return -(int)num;
                }
            }
            /* code */
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
};

int main()
{
    cout << "Hello" << endl;

    string tmp = "228552307";
    // string tmp = "91283472332";

    Solution cbr;
    cout << "dsafdsag" << cbr.myAtoi(tmp);
    // cout << cbr.study(num1, num2);
    return 0;
}

// 请你来实现一个 atoi 函数，使其能将字符串转换成整数。

// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

// 当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

// 该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

// 在任何情况下，若函数不能进行有效的转换时，请返回 0。

// 说明：

// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/string-to-integer-atoi
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。