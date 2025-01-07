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
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;
        ListNode* ans = NULL;

        if (left->val < right->val) {
            ans = left;
            ans->next = merge(left->next, right);
        } else {
            ans = right;
            ans->next = merge(left, right->next);
        }

        return ans;
    }

    ListNode* mid(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* middle = mid(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};