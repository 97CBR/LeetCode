// 西山居笔试题 第二题，
// 在主串中删除 模式串中出现过的所有字符
// 例如：
// input：welcome to amazing seasun
// output：lom to mzing ssun

// 思路：
// 遍历模式串，每遍历一个模式串中的字符，就在主串中寻找，然后将其用replace替换“”
// 直到寻找不到模式串中的字符

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
