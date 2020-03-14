// 780. 到达终点
// 从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。

// 给定一个起点 (sx, sy) 和一个终点 (tx, ty)，如果通过一系列的转换可以从起点到达终点，则返回 True ，否则返回 False。

// 示例:
// 输入: sx = 1, sy = 1, tx = 3, ty = 5
// 输出: True
// 解释:
// 可以通过以下一系列转换从起点转换到终点：
// (1, 1) -> (1, 2)
// (1, 2) -> (3, 2)
// (3, 2) -> (3, 5)

// 输入: sx = 1, sy = 1, tx = 2, ty = 2
// 输出: False

// 输入: sx = 1, sy = 1, tx = 1, ty = 1
// 输出: True

// 思路：
// 从最开始的坐标进行遍历查找显然不是个好方法
// 在这里采用从后往前进行查找上一步坐标的办法
// 例如，3,5 就只能由 3,2 这一种可能
// 3,2 就只有 1,2 这一种可能
// 然后一路下去，直到 1,1 或者 其中一个小于起始坐标，或者小于0就退出

// 这样子会出现 tx或者tx与sx、sy相差很多的时候，运行很慢的问题
// 所以，进行取模优化。为了避免取完模之后小于 起点的xy，得加到其大于xy
// 然后再运行就快了

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
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {

        if (sx == tx && ty == sy)
        {
            // cout << "start is target" << endl;
            return true;
        }
        if (tx < sx || ty < sy)
        {
            // cout << "you can't do it" << endl;
            return false;
        }
        int tmp_tx = tx;
        int tmp_ty = ty;
        if (tx != ty)
        {

            int ax = tx;
            int ay = ty;

            if (tx > ty)
            {
                tx = tx % ty;
                while (tx < sx)
                {
                    tx += ty;
                }
            }
            else
            {
                ty = ty % tx;
                while (ty < sy)
                {
                    ty += tx;
                }
            }
            while (ax != ay)
            {

                ax = tx;
                ay = ty;
                if (ax == sx && ay == sy)
                {
                    // cout << "you can do it" << endl;
                    return true;
                }
                if (ax <= 0 || ay <= 0)
                {
                    cout << "you can't do it" << endl;
                    return false;
                }
                // int tmp_p = sx + sy;

                int rex = abs(tx - ty);
                ax = tx > ty ? rex : tx;
                ay = tx > ty ? ty : rex;
                cout << "pre sept" << ax << "\t" << ay << endl;
                tx = ax;
                ty = ay;
                if (ax == sx && ay == sy)
                {
                    // cout << "you can do it" << endl;
                    return true;
                }
                if (ax <= 0 || ay <= 0 || ax < sx || ay < sy)
                {
                    // cout << "you can't do it" << endl;
                    break;
                }
            }
        }
        // cout << "you can't do it" << endl;

        return false;
    }
};

int main()
{
    cout << "Hello" << endl;

    int sx, sy, tx, ty = 0;
    // sx = 1;
    // sy = 4;
    // tx = 999999998;
    // ty = 4;

    sx = 4;
    sy = 9;
    tx = 188;
    ty = 117;

    // sx = 45;
    // sy = 37;
    // tx = 193;
    // ty = 37;

    // sx = 3;
    // sy = 3;
    // tx = 12;
    // ty = 9;

    // sx = 10;
    // sy = 5;
    // tx = 15;
    // ty = 5;

    // sx = 1;
    // sy = 8;
    // tx = 4;
    // ty = 15;

    // sx = 3;
    // sy = 7;
    // tx = 3;
    // ty = 4;

    Solution cbr;
    cbr.reachingPoints(sx, sy, tx, ty);
    // cout << << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}