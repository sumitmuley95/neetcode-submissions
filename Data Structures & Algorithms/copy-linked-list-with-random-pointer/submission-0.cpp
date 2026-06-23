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
        if(!head) return head;

        Node* iterator = head;

        while(iterator) {
            Node* iteratorChaNext = iterator->next;
            Node* dummy = new Node(iterator->val);
            iterator->next = dummy;
            dummy->next = iteratorChaNext;
            iterator = iteratorChaNext;
        }

        iterator = head;
        while(iterator) {
            Node* dummy = iterator->next;
            if(iterator->random) dummy->random = iterator->random->next;
            else dummy->random = nullptr;
            iterator = dummy->next;
        }

        Node* newHead = head->next;
        iterator = head;
        while(iterator) {
            Node* dummy = iterator->next;
            iterator->next = dummy->next;

            if(dummy->next) {
                dummy->next = dummy->next->next;
            }

            iterator = iterator->next;
        }
        return newHead;
    }
};
