// 300. 最长上升子序列
// 给定一个无序的整数数组，找到其中最长上升子序列的长度。

// 示例:

// 输入: [10,9,2,5,3,7,101,18]
// 输出: 4
// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
// 说明:

// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
// 你算法的时间复杂度应该为 O(n2) 。
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?


// 思路：
// 创建一个容器，用来保存所有的上升序列
// 在确定上升序列中，使用 a< b ,即将b插入
// 如a<b && b>c && a<c 的情况下，将b换成c
// 具体可以在下面第二层循环中见到
// 此解决方案的 复杂度为 N的平方


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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> &ftv = nums;
        if (ftv.size() < 1)
        {
            return 0;
        }
        if (ftv.size() == 1)
        {
            return 1;
        }
        int x, y = 0;
        vector<vector<int>> res;
        for (int i = 0; i < ftv.size(); i++)
        {
            x = ftv.at(i);
            vector<int> tmp_res;
            tmp_res.push_back(x);
            for (int j = i + 1; j < ftv.size(); j++)
            {
                y = ftv.at(j);
                if (tmp_res.at(tmp_res.size() - 1) < y)
                {
                    tmp_res.push_back(y);
                }
                if (tmp_res.size() > 1 && tmp_res.at(tmp_res.size() - 1) > y && tmp_res.at(tmp_res.size() - 2) < y)
                {
                    tmp_res.at(tmp_res.size() - 1) = y;
                }
            }

            res.push_back(tmp_res);
        }
        sort(res.begin(), res.end(), [](const vector<int> &a1, const vector<int> &a2) {
            return a1.size() > a2.size();
        });
        cout << res.at(0).size() << endl;
        return res.at(0).size();
    }
};

int main()
{
    cout << "Hello" << endl;

    string target = "babad";
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // vector<int> nums = {10, 9, 2, 5, 3, 4};
    // vector<int> nums = {4, 10, 4, 3, 8, 9};
    // nums.push_back(0);

    Solution cbr;
    cbr.lengthOfLIS(nums);
    // cout << << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
