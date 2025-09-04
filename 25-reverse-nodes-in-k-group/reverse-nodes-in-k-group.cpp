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

        stack<ListNode*> st;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {
            int cnt = 0;
            ListNode* temp = curr;
            while (temp && cnt < k) {
                st.push(temp);
                temp = temp->next;
                cnt++;
            }

            if (cnt != k) {
                prev->next = curr;
                return head;
            }

            while (!st.empty()) {
                if (!prev) {
                    prev = st.top();
                    head = prev;
                } else {
                    prev->next = st.top();
                    prev = prev->next;
                }
                st.pop();
            }

            prev->next = temp;
            curr = temp;
        }

        return head;
    }
};