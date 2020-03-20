// https : //leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// 面试题40. 最小的k个数
// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。



// 示例 1：

// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]

#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <stl_queue.h>

        using namespace std;

class Solution
{
public:
    vector<int> direct_sort(vector<int> &arr, int k)
    {
        vector<int> res_vec;
        if (arr.size() <= k)
        {
            res_vec = arr;
            return res_vec;
        }
        if (k == 0)
        {
            return res_vec;
        }
        sort(arr.begin(), arr.end());

        for (int i = 0; i < k; i++)
        {
            res_vec.push_back(arr.at(i));
        }

        return res_vec;
    }

    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        vector<int> res_vec;
        if (arr.size() <= k)
        {
            res_vec = arr;
            return res_vec;
        }
        if (k == 0)
        {
            return res_vec;
        }

        priority_queue<int> tmp;

        for (int i = 0; i < k; i++)
        {
            tmp.push(arr.at(i));
        }

        for (int j = k; j < arr.size(); j++)
        {
            if (arr.at(j) < tmp.top())
            {
                tmp.pop();
                tmp.push(arr.at(j));
            }
        }
        while (!tmp.empty())
        {
            res_vec.push_back(tmp.top());
            tmp.pop();
        }
        return res_vec;
    }
};

int main()
{
    cout << "Hello" << endl;

    vector<int> arr = {0, 0, 0, 2, 0, 5};
    int target = 0;

    // vector<int> arr = {3, 2, 1};
    // int target = 2;

    // string target = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";

    Solution cbr;
    cbr.getLeastNumbers(arr, target);

    return 0;
}
