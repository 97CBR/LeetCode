// 33. ������ת��������
// ���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

// ( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��

// ����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��

// ����Լ��������в������ظ���Ԫ�ء�

// ����㷨ʱ�临�Ӷȱ����� O(log n) ����

// ʾ�� 1:

// ����: nums = [4,5,6,7,0,1,2], target = 0
// ���: 4
// ʾ�� 2:

// ����: nums = [4,5,6,7,0,1,2], target = 3
// ���: -1

// ˼·��
// ���ȴ�������м�Ԫ�ؿ�ʼ�����������߱�����Ѱ�ҳ��Ƿ��У��ұ߱����С��Ԫ��
// �����Ϳ���ȷ�����Ƿ�Ϊ��ת����
// ȷ���Ƿ���ת�����
// ���Ǽ�ֱ�ӽ��ж��ֲ���
// �����ж�Ŀ��ֵ���������߻����ұ�
// Ȼ���ٵ��ö��ֲ��Ҽȿ��Խ���������

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
    int two_split_find(vector<int> &nums, int target, int index_s, int index_e)
    {
        if (index_s > index_e)
        {
            return -1;
        }
        int tmp = index_s + (index_e - index_s) / 2;
        if (nums.at(tmp) == target)
        {
            cout << "find your index\t" << tmp << "\telem\t" << nums.at(tmp) << endl;
            return tmp;
        }
        else if (nums.at(tmp) > target)
        {
            return two_split_find(nums, target, index_s, tmp - 1);
        }
        else if (nums.at(tmp) < target)
        {
            return two_split_find(nums, target, tmp + 1, index_e);
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {

        int elem_nums = nums.size();
        if (elem_nums == 0)
        {
            cout << -1 << endl;
            return -1;
        }
        else if (elem_nums == 1)
        {
            cout << ((nums.at(0) == target) ? 0 : -1) << endl;
            return (nums.at(0) == target ? 0 : -1);
        }
        nums.push_back(nums.at(0));
        nums.push_back(nums.at(0));
        if (!(elem_nums % 2))
        {
            nums.push_back(nums.at(0));
        }

        elem_nums = nums.size();
        int index_m = elem_nums / 2;
        int index_res = -1;
        for (int i = 0; i < index_m; i++)
        {
            cout << nums.at(index_m + i) << endl;
            cout << nums.at(index_m - i) << endl;
            if (nums.at(index_m + i - 1) > nums.at(index_m + i))
            {
                cout << "find you" << nums.at(index_m + i - 1) << endl;
                index_res = index_m + i - 1;
                break;
            }
            else if (nums.at(index_m - i - 1) > nums.at(index_m - i))
            {
                cout << "find you" << nums.at(index_m - i - 1) << endl;
                index_res = index_m - i - 1;
                break;
            }
        }
        if (index_res == -1)
        {
            cout << "û����ת��" << endl;
            int res = two_split_find(nums, target, 0, elem_nums - 1);
            cout << res << endl;
            return res;
        }

        cout << "find your index\t" << index_res << "\telem\t" << nums.at(index_res) << endl;
        if (target == nums.at(index_res))
        {
            cout << "��ת�����Ŀ��" << endl;
            cout << index_res << endl;
            return index_res;
        }
        else if (target >= nums.at(index_res + 1) && target < nums.at(0))
        {
            cout << "��ת���ұ�Ѱ��" << endl;
            int res = two_split_find(nums, target, index_res + 1, elem_nums - 1);
            cout << res << endl;
            return res;
        }
        else
        {
            cout << "��ת�����Ѱ��" << endl;
            int res = two_split_find(nums, target, 0, index_res);
            cout << res << endl;
            return res;
        }

        return 0;
    }
};

int main()
{
    cout << "Hello" << endl;

    vector<int> nums = {1, 3};
    int target = 0;
    // nums.push_back(0);

    Solution cbr;
    cout << cbr.search(nums, target) << endl;

    nums = {1};
    target = 1;
    cout << cbr.search(nums, target) << endl;

    nums = {};
    target = 1;
    cout << cbr.search(nums, target) << endl;

    nums = {1};
    target = 2;
    cout << cbr.search(nums, target) << endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    cout << cbr.search(nums, target) << endl;

    nums = {4, 5, 1};
    target = 1;
    cout << cbr.search(nums, target) << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
