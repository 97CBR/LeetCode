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
    string longestPalindrome(string s)
    {
        // s.reserve();

        if (!(s.length() % 2))
        {
            s += "#";
        }
        int tmp = s.length() / 2;
        // reverse(s.begin(), s.end());
        cout << s << tmp << endl;
        for (int i = tmp; i > 0; i--)
        {
            string lts = s.substr(tmp - i, tmp);
            string rts = s.substr(tmp + 1, tmp + i);
            cout << lts << "\t" << rts << endl;
        }

        return s;
    }
};

int main()
{
    cout << "Hello" << endl;

    string target = "babad";
    // nums.push_back(0);

    Solution cbr;
    cbr.longestPalindrome(target);
    // cout << << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
