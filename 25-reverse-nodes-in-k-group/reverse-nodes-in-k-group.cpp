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
    ListNode* kthnode(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 1; i < k && temp; i++)
            temp = temp->next;
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp) {
            ListNode* kthNode = kthnode(temp, k);
         if(kthNode==NULL) {
            if(prev) prev->next=temp;
            break;
         } 
         ListNode *nxt=kthNode->next;
          kthNode->next=NULL;

        reverse(temp); 
        if(temp==head) head=kthNode;
       else prev->next=kthNode;
       
       prev=temp;
       temp=nxt;
        }
        return head;
    }
};