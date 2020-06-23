#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

class Solution
{
public:
    void battle_num(int aim_num, vector<int> &mans)
    {
        int all_battle = 0;
        int ret = 0;
        while (ret < aim_num)
        {

            if (mans.at(0) > mans.at(1))
            {
                int tmp = mans.at(1);
                mans.erase(mans.begin() + 1);
                mans.push_back(tmp);
                ret += 1;
            }
            else
            {
                int tmp = mans.at(0);
                mans.erase(mans.begin());
                mans.push_back(tmp);
                ret = 1;
            }
            all_battle += 1;
        }
        cout << all_battle << endl;
    }


    void battle(int aim_num, int *mans, int len)
    {
        int all_battle = 0;
        int ret = 0;
        int *ci = mans;
        while (ret < aim_num)
        {
            if (*ci > *(ci + 1))
            {
                int tmp = *(ci + 1);
                *(ci + len) = tmp;
                *(ci + 1) = *ci;
                ci = ci + 1;
                ret += 1;
            }
            else
            {
                int tmp = *ci;
                *(ci + len) = tmp;
                ci = ci + 1;
                ret = 1;
            }
            all_battle += 1;
        }
        cout << all_battle << endl;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    int *ap = new int[m * 2];
    memset(ap, 0, m * 2);
    int gg = 0;

    queue<int> q;
    for (int i = 0; i < m; i++)
    {

        cin >> gg;
        q.push(gg);
    }
    Solution cbr;
    cbr.battle(n, q);
    return 0;
}