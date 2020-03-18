// 836. 矩形重叠
// 矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。

// 如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。

// 给出两个矩形，判断它们是否重叠并返回结果。

// 示例 1：

// 输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
// 输出：true

// https : //leetcode-cn.com/problems/rectangle-overlap/

// 思路
// 将两个矩形的x1, y1, x2, y2的对角指向明确，从坐下往右上指
// 可以通过比 x1 x2 的大小来实现
// 然后再判断其最大和最小的点，是否存在于第一个矩阵。
// 然后即可解出这题

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
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        if (rec1.at(0) > rec1.at(2))
        {
            int tmp = rec1.at(0);
            rec1.at(0) = rec1.at(2);
            rec1.at(2) = tmp;
            // return isRectangleOverlap(rec2, rec1);
        }
        if (rec2.at(0) > rec2.at(2))
        {
            int tmp = rec2.at(0);
            rec2.at(0) = rec2.at(2);
            rec2.at(2) = tmp;
            // return isRectangleOverlap(rec2, rec1);
        }

        int x1 = rec1.at(0);
        int x2 = rec1.at(2);
        int y1 = rec1.at(1);
        int y2 = rec1.at(3);

        int x1_x = rec2.at(0);
        int x2_x = rec2.at(2);
        int y1_x = rec2.at(1);
        int y2_x = rec2.at(3);

        if (x2_x <= x1 || x1_x >= x2)
        {
            return false;
        }
        if (y2_x <= y1 || y1_x >= y2)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    cout << "Hello" << endl;
    // vector<int> rec1 = {0, 0, 2, 2};
    // vector<int> rec2 = {1, 1, 3, 3};
    // [ 2, 17, 6, 20 ]
    //     [3, 8, 6, 20]
    // vector<int> rec1 = {2, 17, 6, 20};
    // vector<int> rec2 = {3, 8, 6, 20};
    vector<int> rec1 = {0, 0, 1, 1};
    vector<int> rec2 = {1, 0, 2, 1};

    Solution cbr;
    cout << cbr.isRectangleOverlap(rec1, rec2) << endl;

    return 0;
}
