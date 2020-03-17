// 给你一份『词汇表』（字符串数组）?words?和一张『字母表』（字符串）?chars。

// 假如你可以用?chars?中的『字母』（字符）拼写出 words?中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

// 注意：每次拼写时，chars 中的每个字母都只能用一次。

// 返回词汇表?words?中你掌握的所有单词的 长度之和。

// ?

// 示例 1：

// 输入：words = ["cat","bt","hat","tree"], chars = "atach"
// 输出：6
// 解释：
// 可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 思路：
// 遍历容器内的所有单词
// 如果长度小于等于 给定的chars就进行下一步
// 从单词的第一个单词开始搜索
// 找到chars里面的字符，就用replace删除一个chars里面的字符
// 找不到直接break，返回就可以
// 然后将单词长度加起来即可


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
    int countCharacters(vector<string> &words, string chars)
    {
        int result = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string tmp = words.at(i);
            if (tmp.length() <= chars.length())
            {
                string c_str = chars;
                int flag = 1;
                for (int j = 0; j < tmp.length(); j++)
                {
                    int index = c_str.find_first_of(tmp.at(j));

                    if (index != c_str.npos)
                    {
                        c_str.replace(index, 1, "");
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    // cout << words.at(i) << endl;
                    result += words.at(i).length();
                }
            }
        }
        return result;
    }
};

int main()
{
    cout << "Hello" << endl;

    // vector<string> words = {"cat", "bt", "hat", "tree"};
    // vector<string> words = {"hello", "world", "leetcode"};
    vector<string> words = {"hello", "world", "leetcode"};
    string chars = "welldonehoneyr";

    // string target = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";

    Solution cbr;
    cout << cbr.countCharacters(words, chars) << endl;

    return 0;
}
