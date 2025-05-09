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
    void deleteNode(ListNode* node) {
        ListNode *temp=node;
        ListNode *dummy=new ListNode(-1);

        while(temp->next){
            temp->val=temp->next->val;
            dummy=temp;
            temp=temp->next;
        }
        dummy->next=NULL;
    }
};