// ����һ�ݡ��ʻ�����ַ������飩?words?��һ�š���ĸ�����ַ�����?chars��

// �����������?chars?�еġ���ĸ�����ַ���ƴд�� words?�е�ĳ�������ʡ����ַ���������ô���Ǿ���Ϊ��������������ʡ�

// ע�⣺ÿ��ƴдʱ��chars �е�ÿ����ĸ��ֻ����һ�Ρ�

// ���شʻ��?words?�������յ����е��ʵ� ����֮�͡�

// ?

// ʾ�� 1��

// ���룺words = ["cat","bt","hat","tree"], chars = "atach"
// �����6
// ���ͣ�
// �����γ��ַ��� "cat" �� "hat"�����Դ��� 3 + 3 = 6��

// ��Դ�����ۣ�LeetCode��
// ���ӣ�https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
// ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


// ˼·��
// ���������ڵ����е���
// �������С�ڵ��� ������chars�ͽ�����һ��
// �ӵ��ʵĵ�һ�����ʿ�ʼ����
// �ҵ�chars������ַ�������replaceɾ��һ��chars������ַ�
// �Ҳ���ֱ��break�����ؾͿ���
// Ȼ�󽫵��ʳ��ȼ���������


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
