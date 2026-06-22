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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* newHead = reverse(head);

        if (n == 1) {
            ListNode* nodeToDelete = newHead;
            newHead = newHead->next;
            delete nodeToDelete;
            return reverse(newHead);
        }

        ListNode* curr = newHead;
        for (int i = 1; i < n - 1 && curr; i++) {
            curr = curr->next;
        }

        if (curr && curr->next) {
            ListNode* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
        }

        return reverse(newHead);
    }
};