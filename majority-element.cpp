
// ����һ����СΪ n �����飬�ҵ����еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ������� ? n/2 ? ��Ԫ�ء�

// ����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�

// ʾ�� 1:

// ����: [3,2,3]
// ���: 3


// ˼·:
// �ȱ���һ��,����Ԫ����������ʼ��һ����������Ԫ�ص�map
// Ȼ���ٱ���һ�Σ��������map�±��Ԫ�����Զ���һ
// Ȼ��ʹ�� lambda����������һ������
// ���ص�һ��vector�е�Ԫ�ص���ߵ�key�Ϳ�����
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
            // ʹ��˫��ѭ������42�������в��Բ�ͨ��
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

        // ��ԭ�ȵ�mapתΪvector���д�����Ϊ���������ֱ�ӽ���sort
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
