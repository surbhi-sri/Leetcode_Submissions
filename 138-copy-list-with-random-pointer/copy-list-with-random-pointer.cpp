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

        if (!head)
            return NULL;

        Node* temp = head;
        while (temp) {
            Node* nxt = temp->next;
            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = nxt;
            temp = nxt;
        }
        temp = head;

        while (temp) {
            Node* copy = temp->next;
            copy->random = temp->random ? temp->random->next : NULL;
            temp = copy->next;
        }

        Node* Nhead = head->next;
        temp = head;

        while (temp) {
            Node* nxt = temp->next->next;
            temp->next->next = nxt ? nxt->next : NULL;
            temp->next = nxt;
            temp = nxt;
        }

        return Nhead;
    }
};