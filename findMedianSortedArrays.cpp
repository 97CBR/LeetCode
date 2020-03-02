#include <iostream>
#include <vector>
using namespace std;

// 寻找两个有序数组的中位数

// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

// 你可以假设 nums1 和 nums2 不会同时为空。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution
{

private:
    int first_size;
    int second_size;
    int number;

public:
    // 在CSDN中找到的，将其化为TOPK的解法
    // double study(vector<int> &nums1, vector<int> &nums2)
    // {

    //     int n = nums1.size();
    //     int m = nums2.size();
    //     if (n > m) //保证数组1一定最短
    //         return findMedianSortedArrays(nums2, nums1);
    //     int L1, L2, R1, R2, c1, c2, lo = 0, hi = 2 * n; //我们目前是虚拟加了'#'所以数组1是2*n长度
    //     while (lo <= hi)                                //二分
    //     {
    //         c1 = (lo + hi) / 2; //c1是二分的结果
    //         c2 = m + n - c1;
    //         L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2]; //map to original element
    //         R1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
    //         L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
    //         R2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

    //         if (L1 > R2)
    //             hi = c1 - 1;
    //         else if (L2 > R1)
    //             lo = c1 + 1;
    //         else
    //             break;
    //     }
    //     return (max(L1, L2) + min(R1, R2)) / 2.0;
    // }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        number = nums1.size() + nums2.size();

        if (number % 2)
        {
            cout << "odd number" << endl;
        }
        else
        {
            cout << "even number" << endl;
        }
        first_size = nums1.size();
        second_size = nums2.size();

        if (first_size > second_size)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int index_s = 0;
        int index_e = nums1.size();
        int index_m = (first_size + second_size + 1) / 2;
        while (index_s <= index_e)
        {
            int i = (index_s + index_e) / 2;
            int j = index_m - i;
            if (i < index_e && nums2.at(j - 1) > nums1.at(i))
            {
                index_s = i + 1;
            }
            else if (i > index_s && nums1.at(i - 1) > nums2.at(j))
            {
                index_e = i - 1;
            }
            else
            {
                int max_l;
                if (i == 0)
                {
                    max_l = nums2.at(j - 1);
                }
                else if (j == 0)
                {
                    max_l = nums1.at(i - 1);
                }
                else
                {
                    max_l = (nums1.at(i - 1) > nums2.at(j - 1)) ? nums1.at(i - 1) : nums2.at(j - 1);
                }
                if (number % 2)
                {
                    cout << max_l / 1.0 << endl;
                    return max_l / 1.0;
                }
                cout << "max l" << max_l / 1.0 << endl;
                int min_r;
                if (i == first_size)
                {
                    min_r = nums2.at(j);
                }
                else if (j == second_size)
                {
                    min_r = nums1.at(i);
                }
                else
                {
                    min_r = (nums1.at(i) < nums2.at(j)) ? nums1.at(i) : nums2.at(j);
                }
                cout << "min r" << min_r / 1.0 << endl;
                cout << "res\t" << (max_l + min_r) / 2.0 << endl;
                return (max_l + min_r) / 2.0;
            }
        }
        return 0.0;
        // deal(nums1, nums2);
    }
};

int main()
{
    cout << "Hello" << endl;
    Solution cbr;
    vector<int> num1;
    vector<int> num2;
    num1.push_back(1);
    num1.push_back(2);
    // num1.push_back(2);

    num2.push_back(-1);
    num2.push_back(3);
    // num2.push_back(7);

    cbr.findMedianSortedArrays(num1, num2);
    // cout << cbr.study(num1, num2);
    return 0;
}
