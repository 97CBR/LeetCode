#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    void sum_two(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums.at(i) << endl;
        }
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int ele_num = nums.size();
        vector<int> tmp;
        for (int i = 0; i < ele_num; i++)
        {
            tmp = nums;
            tmp.erase(tmp.begin() + i);
            sum_two(tmp);
        }
    }
};

int main()
{
    cout << "Hello" << endl;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    // string tmp = "91283472332";

    Solution cbr;
    cbr.threeSum(nums);
    // cout << cbr.study(num1, num2);
    return 0;
}
