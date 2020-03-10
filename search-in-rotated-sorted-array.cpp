// 33. 搜索旋转排序数组
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

// 你可以假设数组中不存在重复的元素。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 示例 1:

// 输入: nums = [4,5,6,7,0,1,2], target = 0
// 输出: 4
// 示例 2:

// 输入: nums = [4,5,6,7,0,1,2], target = 3
// 输出: -1

// 思路：
// 首先从数组的中间元素开始，往左右两边遍历，寻找出是否有，右边比左边小的元素
// 这样就可以确定了是否为旋转数组
// 确定是否旋转数组后
// 不是即直接进行二分查找
// 是则判断目标值在数组的左边还是右边
// 然后再调用二分查找既可以解决这个问题

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
    int two_split_find(vector<int> &nums, int target, int index_s, int index_e)
    {
        if (index_s > index_e)
        {
            return -1;
        }
        int tmp = index_s + (index_e - index_s) / 2;
        if (nums.at(tmp) == target)
        {
            cout << "find your index\t" << tmp << "\telem\t" << nums.at(tmp) << endl;
            return tmp;
        }
        else if (nums.at(tmp) > target)
        {
            return two_split_find(nums, target, index_s, tmp - 1);
        }
        else if (nums.at(tmp) < target)
        {
            return two_split_find(nums, target, tmp + 1, index_e);
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {

        int elem_nums = nums.size();
        if (elem_nums == 0)
        {
            cout << -1 << endl;
            return -1;
        }
        else if (elem_nums == 1)
        {
            cout << ((nums.at(0) == target) ? 0 : -1) << endl;
            return (nums.at(0) == target ? 0 : -1);
        }
        nums.push_back(nums.at(0));
        nums.push_back(nums.at(0));
        if (!(elem_nums % 2))
        {
            nums.push_back(nums.at(0));
        }

        elem_nums = nums.size();
        int index_m = elem_nums / 2;
        int index_res = -1;
        for (int i = 0; i < index_m; i++)
        {
            cout << nums.at(index_m + i) << endl;
            cout << nums.at(index_m - i) << endl;
            if (nums.at(index_m + i - 1) > nums.at(index_m + i))
            {
                cout << "find you" << nums.at(index_m + i - 1) << endl;
                index_res = index_m + i - 1;
                break;
            }
            else if (nums.at(index_m - i - 1) > nums.at(index_m - i))
            {
                cout << "find you" << nums.at(index_m - i - 1) << endl;
                index_res = index_m - i - 1;
                break;
            }
        }
        if (index_res == -1)
        {
            cout << "没有旋转点" << endl;
            int res = two_split_find(nums, target, 0, elem_nums - 1);
            cout << res << endl;
            return res;
        }

        cout << "find your index\t" << index_res << "\telem\t" << nums.at(index_res) << endl;
        if (target == nums.at(index_res))
        {
            cout << "旋转点就是目标" << endl;
            cout << index_res << endl;
            return index_res;
        }
        else if (target >= nums.at(index_res + 1) && target < nums.at(0))
        {
            cout << "旋转点右边寻找" << endl;
            int res = two_split_find(nums, target, index_res + 1, elem_nums - 1);
            cout << res << endl;
            return res;
        }
        else
        {
            cout << "旋转点左边寻找" << endl;
            int res = two_split_find(nums, target, 0, index_res);
            cout << res << endl;
            return res;
        }

        return 0;
    }
};

int main()
{
    cout << "Hello" << endl;

    vector<int> nums = {1, 3};
    int target = 0;
    // nums.push_back(0);

    Solution cbr;
    cout << cbr.search(nums, target) << endl;

    nums = {1};
    target = 1;
    cout << cbr.search(nums, target) << endl;

    nums = {};
    target = 1;
    cout << cbr.search(nums, target) << endl;

    nums = {1};
    target = 2;
    cout << cbr.search(nums, target) << endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    cout << cbr.search(nums, target) << endl;

    nums = {4, 5, 1};
    target = 1;
    cout << cbr.search(nums, target) << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
