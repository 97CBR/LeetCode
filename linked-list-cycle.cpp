// 141. 环形链表
// 给定一个链表，判断链表中是否有环。

// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

// 示例 1：

// 输入：head = [3,2,0,-4], pos = 1
// 输出：true
// 解释：链表中有一个环，其尾部连接到第二个节点。

// https : //leetcode-cn.com/problems/linked-list-cycle/

// 思路：
// 假设有环,设置一个快慢指针,一个走一步\一个走两步
// 如果有环,必会出现 两个指针一样的情况,即可判断

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
