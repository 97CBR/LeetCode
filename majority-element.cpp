
// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ? n/2 ? 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

// 示例 1:

// 输入: [3,2,3]
// 输出: 3


// 思路:
// 先遍历一次,按照元素内容来初始化一个包含所有元素的map
// 然后再遍历一次，如果符合map下标的元素则自动加一
// 然后使用 lambda函数，进行一个排序
// 返回第一个vector中的元素的左边的key就可以了
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
    int majorityElement(vector<int> &nums)
    {
        int aim_num = nums.size() / 2;
        int tmp[nums.size()] = {0};

        map<int, int> map_elem;
        for (int i = 0; i < nums.size(); i++)
        {
            int cou = 0;
            tmp[nums.at(i) % nums.size()] += 1;
            map_elem.insert(pair<int, int>(nums.at(i), 0));
            // 使用双重循环，在42个样例中测试不通过
            // for (int j = 0; j< nums.size();j++)
            // {
            //     if (nums.at(j) == nums.at(i))
            //     {
            //         cou += 1;
            //         if (cou > aim_num)
            //         {
            //             cout << "find you" << nums.at(i) << endl;
            //             return nums.at(i);
            //             break;
            //         }
            //     }
            // }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            map_elem.at(nums.at(i)) += 1;
        }

        // 将原先的map转为vector进行处理，因为红黑树不能直接进行sort
        std::vector<std::pair<int, int>> map_vec(map_elem.begin(), map_elem.end());

        std::sort(map_vec.begin(), map_vec.end(),
                  [](const pair<int, int> &x, const pair<int, int> &y) -> int { return x.second > y.second; });

        // for (auto iter = map_vec.rbegin(); iter != map_vec.rend(); iter++)

        //     cout << iter->first << "  " << iter->second << endl;

        cout << map_vec.at(0).first << endl;

        return map_vec.at(0).first;
    }
};

int main()
{
    cout << "Hello" << endl;

    string target = "babad";
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums = {7, 4, 4};
    // nums.push_back(0);

    Solution cbr;
    cbr.majorityElement(nums);
    // cout << << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
