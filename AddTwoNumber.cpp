/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *add(ListNode *l1, ListNode *l2, int i)
    {
        if (!l1 && !l2)
        {
            if (!i)
                return NULL;
            else
            {
                ListNode *p = new ListNode(i);
            }
        }
        int a = 0, b = 0, s, n;
        if (l1)
            a = l1->val;
        if (l2)
            b = l2->val;
        s = a + b + i;
        i = 0;
        if (s > 9)
        {
            s = s - 10;
            i = 1;
        }
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
        ListNode *temp = new ListNode(s);
        temp->next = add(l1, l2, i);
        return temp;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return add(l1, l2, 0);
    }
};