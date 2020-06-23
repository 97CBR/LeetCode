#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void points(vector<pair<int *, char *>> &mans)
    {
        for (auto &ele : mans)
        {
            int res = ele.first[0];
            if (ele.second[0] == 'x' || ele.second[0] == '/')
            {
                res = 0;
            }
            char per = '\0';
            for (int i = 0; i < 3; i++)
            {
                
            }

            if (res == 24)
            {
                cout << "Yes" << endl;
                res = 0;
            }
            else
            {
                cout << "No" << endl;
                res = 0;
            }
            // cout << "res " << res << endl;
        }
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    // opt['+'] = opt['-'] = 0;
    // opt['*'] = opt['/'] = 1;
    // getchar();
    string tmp;
    vector<pair<int *, char *>> task;

    while (n > 0)
    {
        int *nums = new int[5];
        char *flag = new char[4];
        scanf("%d%c%d%c%d%c%d", &nums[0], &flag[0], &nums[1], &flag[1],
              &nums[2], &flag[2], &nums[3]);
        // getline(cin, tmp);
        // cout << nums[0] << nums[1] << endl;
        task.push_back(make_pair(nums, flag));
        --n;
    }
    Solution cbr;
    cbr.points(task);
    return 0;
}
