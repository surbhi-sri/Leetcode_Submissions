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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return 0;

ListNode *first=head;
ListNode *sec=head->next;
       while(sec!=NULL){
        if(first==sec) return 1;
        first=first->next;
        sec=sec->next;
        if(first==sec) return 1;
     if(sec)  sec=sec->next;;

       }

        return 0;
    }
};