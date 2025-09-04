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
        ListNode* curr = head;
        ListNode* newHead = NULL;
        ListNode* tail = NULL;

        while (curr) {
            ListNode* nodeHead = curr;
            ListNode* temp = curr;
            ListNode* nxt = NULL;
            ListNode* prev = NULL;
            int cnt = 0;

            while (curr && cnt < k) {
             nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;  
             cnt++; 
            }

           if(cnt!=k ){
               curr=prev;
               prev=NULL;
              while (cnt--) {
             nxt=curr->next;
             curr->next=prev;
             prev=curr;
             curr=nxt;  
            } 
         
             if(tail) tail->next=temp;
             else return temp;
             break;
            }

            if(!newHead) newHead=prev;           

            if(tail) tail->next=prev;

            tail=nodeHead;
                        

        }

        return newHead;
    }
};