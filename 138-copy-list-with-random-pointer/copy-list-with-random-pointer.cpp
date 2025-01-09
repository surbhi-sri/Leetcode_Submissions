/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* mid = new Node(temp->val);
            mid->next = temp->next;
            temp->next = mid;
            temp = temp->next->next;
        }
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while (temp) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};