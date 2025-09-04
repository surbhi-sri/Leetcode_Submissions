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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        deque<ListNode*> dq;
        ListNode* curr = head;

        while (curr) {
            int cnt = 0;
            while (curr && cnt < k) {
                dq.push_front(curr);
                curr = curr->next;
                cnt++;
            }

            if (cnt != k)
                break;

            while (!dq.empty()) {
                ListNode* front = dq.front();
                ListNode* back = dq.back();

                swap(front->val, back->val);
                if (!dq.empty())
                    dq.pop_front();
                if (!dq.empty())
                    dq.pop_back();
            }
        }

        return head;
    }
};