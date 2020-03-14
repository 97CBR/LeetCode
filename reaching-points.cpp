// 780. �����յ�
// �ӵ� (x, y) ����ת���� (x, x+y)  ���� (x+y, y)��

// ����һ����� (sx, sy) ��һ���յ� (tx, ty)�����ͨ��һϵ�е�ת�����Դ���㵽���յ㣬�򷵻� True �����򷵻� False��

// ʾ��:
// ����: sx = 1, sy = 1, tx = 3, ty = 5
// ���: True
// ����:
// ����ͨ������һϵ��ת�������ת�����յ㣺
// (1, 1) -> (1, 2)
// (1, 2) -> (3, 2)
// (3, 2) -> (3, 5)

// ����: sx = 1, sy = 1, tx = 2, ty = 2
// ���: False

// ����: sx = 1, sy = 1, tx = 1, ty = 1
// ���: True

// ˼·��
// ���ʼ��������б���������Ȼ���Ǹ��÷���
// ��������ôӺ���ǰ���в�����һ������İ취
// ���磬3,5 ��ֻ���� 3,2 ��һ�ֿ���
// 3,2 ��ֻ�� 1,2 ��һ�ֿ���
// Ȼ��һ·��ȥ��ֱ�� 1,1 ���� ����һ��С����ʼ���꣬����С��0���˳�

// �����ӻ���� tx����tx��sx��sy���ܶ��ʱ�����к���������
// ���ԣ�����ȡģ�Ż���Ϊ�˱���ȡ��ģ֮��С�� ����xy���üӵ������xy
// Ȼ�������оͿ���

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