// 141. ��������
// ����һ�������ж��������Ƿ��л���

// Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

// ʾ�� 1��

// ���룺head = [3,2,0,-4], pos = 1
// �����true
// ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

// https : //leetcode-cn.com/problems/linked-list-cycle/

// ˼·��
// �����л�,����һ������ָ��,һ����һ��\һ��������
// ����л�,�ػ���� ����ָ��һ�������,�����ж�

#include <iostream>
#include <vector>
#include <memory>
#include <string.h>
#include <string>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        cout << "res" << endl;
        ListNode *rhead = head;
        ListNode *f_head = head;
        ListNode *s_head = head;
        bool flag = false;
        while (f_head != NULL && f_head->next != NULL)
        {
            // cout << "f_head->val" << f_head->val << endl;
            // cout << "s_head->val" << s_head->val << endl;
            f_head = f_head->next->next;
            s_head = s_head->next;
            // cout << "f_head->val" << f_head->val << endl;
            // cout << "s_head->val" << s_head->val << endl;
            if (f_head == s_head)
            {
                flag = true;
                break;
            }

            // rhead = rhead->next;
        }

        if (flag)
        {
            cout << "res is " << flag << endl;
        }
        else
        {
            cout << "res is " << flag << endl;
        }
        return flag;
    }
};

int main()
{
    cout << "Hello" << endl;

    vector<int> nums = {1, 3};
    int target = 0;
    // nums.push_back(0);

    ListNode *head = new ListNode(0);

    ListNode *tmp_head = head;

    for (int i = 1; i < 5; i++)
    {
        cout << i << endl;
        head->next = new ListNode(i);
        head = head->next;
    }

    // head->next = tmp_head->next;

    Solution cbr;
    cbr.hasCycle(tmp_head);

    // cout << cbr.hasCycle(tmp_head) << endl;

    // cout << cbr.study(num1, num2);
    return 0;
}
