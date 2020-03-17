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
    bool match(char *str, char *pattern)
    {
        cout << str << endl;
        return true;
    }
};

int main()
{
    cout << "Hello" << endl;

    char *str = "3245632";
    char *pattern = "3245632";

    Solution cbr;
    cbr.match(str, pattern);

    // Solution *csbr = new Solution;
    // csbr->match(str, pattern);

    // cout << duplication << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
