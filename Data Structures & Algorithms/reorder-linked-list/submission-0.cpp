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
    void reverseLL() {

    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        //step 1 find mid
        ListNode* tortoise = head;
        ListNode* hare = head;

        while(hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        //till here where our tortoise is middle 
        ListNode* middle = tortoise->next;
        tortoise->next = nullptr;

        //step 2 mid pasun end parenta reverse kar 
        ListNode* prev = nullptr;
        ListNode* curr = middle;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* last = prev;

        ListNode* first = head;

        while(last) {
            ListNode* firstChaNext = first->next;
            ListNode* lastChaNext = last->next;
            first->next = last;
            last->next = firstChaNext;
            first = firstChaNext;
            last = lastChaNext;
        }
    }
};
