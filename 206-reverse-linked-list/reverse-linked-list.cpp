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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
       ListNode *p=NULL;
       ListNode *q=head;
       ListNode *r=head->next;

       while(r){
        q->next=p;
        p=q;

        ListNode *temp=r;
        q=temp;
        r=r->next;
       }
       
       q->next=p;
       return q;
    }
};