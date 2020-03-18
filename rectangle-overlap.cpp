// 836. �����ص�
// �������б� [x1, y1, x2, y2] ����ʽ��ʾ������ (x1, y1) Ϊ���½ǵ����꣬(x2, y2) �����Ͻǵ����ꡣ

// ����ཻ�����Ϊ��������������ص�����Ҫ��ȷ���ǣ�ֻ�ڽǻ�߽Ӵ����������β������ص���

// �����������Σ��ж������Ƿ��ص������ؽ����

// ʾ�� 1��

// ���룺rec1 = [0,0,2,2], rec2 = [1,1,3,3]
// �����true

// https : //leetcode-cn.com/problems/rectangle-overlap/

// ˼·
// ���������ε�x1, y1, x2, y2�ĶԽ�ָ����ȷ��������������ָ
// ����ͨ���� x1 x2 �Ĵ�С��ʵ��
// Ȼ�����ж���������С�ĵ㣬�Ƿ�����ڵ�һ������
// Ȼ�󼴿ɽ������

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
