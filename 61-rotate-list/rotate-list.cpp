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
    int length(ListNode* head){
    int cnt=0;
     ListNode *temp= head;
     while(temp){
        cnt++;
        temp=temp->next;
     }
     return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
      int len=length(head);  
       if(head==NULL ||head->next==NULL || k==0 || k==len) return head;

     if(k>len) k=k%len;
     if(k==0) return head;
    ListNode *temp= head;
      while(temp && k){
        k--;
        temp=temp->next;
     } 
     
     ListNode *front= head;

    while(temp->next){
        temp=temp->next;
        front=front->next;
    }
     
    ListNode *nxt=front->next;
     front->next=NULL;
     temp->next=head;

     return nxt;

    }
};