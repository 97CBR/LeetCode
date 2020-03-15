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
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() == 0)
        {
            return 0;
        }
        else if (points.size() == 1)
        {
            return 1;
        }
        vector<vector<float>> res_all_line;
        int max_count = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points.at(i)[0];
            int y = points.at(i)[1];

            cout << "x-y"
                 << "\t" << x << "\t" << y << endl;
            vector<float> tmp_all;
            // a*查找不适用，在处理不连续点时错误
            // eight_find(tmp_all, points, x, y);
            for (int j = 0; j < points.size(); j++)
            {
                if (j == i)
                {
                    continue;
                }
                int sx = points.at(j)[0];
                int sy = points.at(j)[1];

                // if (sx == x && sy == y)
                // {
                //     max_count += 1;
                // }

                float ang = 0.0;
                if ((sx - x) != 0)
                {
                    ang = (sy - y) * 1.0 / (sx - x) * 1.0;
                }
                else
                {
                    ang = 0.0;
                }

                cout << "p1-p2\t" << sx << "\t" << sy << "\t" << ang << endl;
                tmp_all.push_back(ang);
            }
            sort(tmp_all.begin(), tmp_all.end());
            //
            res_all_line.push_back(tmp_all);
        }

        for (int k = 0; k < res_all_line.size(); k++)
        {
            for (int g = 0; g < res_all_line.at(k).size(); g++)
            {
                int repeat_num = count(res_all_line.at(k).begin(), res_all_line.at(k).end(), res_all_line.at(k).at(g));
                if (repeat_num >= max_count)
                {
                    max_count = repeat_num;
                }
            }
        }

        // for (int q = 0; q < res_all_line.size(); q++)
        // {
        //     vector<vector<float>> res_all_line_count = res_all_line;

        //     for (int k = 0; k < res_all_line_count.at(0).size()-1; k++)
        //     {

        //         for (int g = 0; g < res_all_line_count.size(); g++)
        //         {
        //             // vector<float> tmp_all_count = res_all_line.at(k);
        //             // int repeat_num = count(res_all_line.at(k).begin(), res_all_line.at(k).end(), res_all_line.at(k).at(g));
        //             // res_all_line_count.at(k)
        //             res_all_line_count.at(g).erase(res_all_line_count.at(g).begin() + k, res_all_line_count.at(g).begin() + k + 1);
        //             // break;
        //         }

        //         for (int l = 0; l < res_all_line_count.size(); l++)
        //         {
        //             int repeat_num = count(res_all_line_count.begin(), res_all_line_count.end(), res_all_line_count.at(l));

        //             if (repeat_num >= max_count)
        //             {
        //                 max_count = repeat_num;
        //             }
        //         }
        //     }
        // }

        // max_count += 1;
        cout << "max point is " << max_count << endl;
        return max_count;
    }
};

int main()
{
    cout << "Hello" << endl;

    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // vector<vector<int>> points = {{1, 1},
    //                               {3, 2},
    //                               {5, 3},
    //                               {4, 1},
    //                               {2, 3},
    //                               {1, 4}};

    vector<vector<int>> points = {
        {1, 1},
        {2, 2},
        // {3, 2},
        {1, 1},
        // {2, 2},
        {2, 2}};

    Solution cbr;
    cbr.maxPoints(points);
    // cout << << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
