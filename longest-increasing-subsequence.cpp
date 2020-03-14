// 300. �����������
// ����һ��������������飬�ҵ���������������еĳ��ȡ�

// ʾ��:

// ����: [10,9,2,5,3,7,101,18]
// ���: 4
// ����: ��������������� [2,3,7,101]�����ĳ����� 4��
// ˵��:

// ���ܻ��ж�������������е���ϣ���ֻ��Ҫ�����Ӧ�ĳ��ȼ��ɡ�
// ���㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(n2) ��
// ����: ���ܽ��㷨��ʱ�临�ӶȽ��͵� O(n log n) ��?


// ˼·��
// ����һ�������������������е���������
// ��ȷ�����������У�ʹ�� a< b ,����b����
// ��a<b && b>c && a<c ������£���b����c
// �������������ڶ���ѭ���м���
// �˽�������� ���Ӷ�Ϊ N��ƽ��


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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> &ftv = nums;
        if (ftv.size() < 1)
        {
            return 0;
        }
        if (ftv.size() == 1)
        {
            return 1;
        }
        int x, y = 0;
        vector<vector<int>> res;
        for (int i = 0; i < ftv.size(); i++)
        {
            x = ftv.at(i);
            vector<int> tmp_res;
            tmp_res.push_back(x);
            for (int j = i + 1; j < ftv.size(); j++)
            {
                y = ftv.at(j);
                if (tmp_res.at(tmp_res.size() - 1) < y)
                {
                    tmp_res.push_back(y);
                }
                if (tmp_res.size() > 1 && tmp_res.at(tmp_res.size() - 1) > y && tmp_res.at(tmp_res.size() - 2) < y)
                {
                    tmp_res.at(tmp_res.size() - 1) = y;
                }
            }

            res.push_back(tmp_res);
        }
        sort(res.begin(), res.end(), [](const vector<int> &a1, const vector<int> &a2) {
            return a1.size() > a2.size();
        });
        cout << res.at(0).size() << endl;
        return res.at(0).size();
    }
};

int main()
{
    cout << "Hello" << endl;

    string target = "babad";
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // vector<int> nums = {10, 9, 2, 5, 3, 4};
    // vector<int> nums = {4, 10, 4, 3, 8, 9};
    // nums.push_back(0);

    Solution cbr;
    cbr.lengthOfLIS(nums);
    // cout << << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
