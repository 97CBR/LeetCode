// 题目描述
// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
// 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
// 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

// https : //www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

// 思路：
// 利用string的特性进行快速作弊，避免双重循环，将 O n 的平方 降为 O n
// 先遍历一次，构建原始的数字字符串
// 然后再遍历一次数字，在string 寻找， 该原始的 最左出现 以及 最右出现 的index
// 如果索引相同则 数字唯一，不同则不唯一，即可返回了

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
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        string tmp = "";
        for (int i = 0; i < length; i++)
        {
            // cout << numbers[i] << endl;
            tmp += to_string(numbers[i]);
        }
        for (int i = 0; i < length; i++)
        {
            // cout << numbers[i] << endl;
            int index_l = tmp.find_first_of(to_string(numbers[i]));
            int index_r = tmp.find_last_of(to_string(numbers[i]));
            if (index_l != index_r)
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello" << endl;

    int nums[] = {2, 3, 1, 0, 2, 5, 3};
    int target_len = 7;
    int duplication;
    // head->next = tmp_head->next;

    Solution cbr;
    cbr.duplicate(nums, target_len, &duplication);

    cout << duplication << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
