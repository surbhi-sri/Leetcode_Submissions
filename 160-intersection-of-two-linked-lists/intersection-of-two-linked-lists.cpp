/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == headB)
            return headA;

        ListNode *p = headA;
        ListNode *q = headB;

        while (p && q && p != q) {
            p = p->next;
            q = q->next;
        }

        if (!p)
            p = headB;
        else if (!q)
            q = headA;
        else
            return p;

        while (p && q && p != q) {
            p = p->next;
            q = q->next;
        }

        if (!p)
            p = headB;
        else if (!q)
            q = headA;
        else
            return p;

        while (p && q && p != q) {
            p = p->next;
            q = q->next;
        }

        return p == q ? p : NULL;
    }
};