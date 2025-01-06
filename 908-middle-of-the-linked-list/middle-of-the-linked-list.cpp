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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode *first=head;
         ListNode *sec=head->next;  
         while(sec!=NULL){
          first=first->next;
          sec=sec->next;
          if(sec!=NULL)  sec=sec->next;
         }
         return first;
    }
};