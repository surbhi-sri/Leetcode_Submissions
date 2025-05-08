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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *slow=head;
        ListNode *fast=head;

        while(cnt!=n){
            cnt++;
            fast=fast->next;
        }

        if(fast==NULL) return slow->next;
    
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }

        slow->next=slow->next->next;

        return head;
    }
};