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
    ListNode* rev(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* stopHere = end->next;
        while(curr != stopHere) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void solve(ListNode* &it, ListNode* &start, ListNode* &end, ListNode* &afterEnd, int val) {
        while(it && val) {
            if(!start) start = it;
            if(val == 1) end = it;
            it = it->next;
            val--;
        }
        afterEnd = it;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* beforeStart = dummy;
        ListNode* it = head;
        
        while(it) {
            ListNode* start = nullptr;
            ListNode* end = nullptr;
            ListNode* afterEnd = nullptr;
            
            solve(it,start,end,afterEnd,k);
            //returns start, end, afterEnd
            if(end != nullptr) {
                rev(start,end);
                beforeStart->next = end;
                start->next = afterEnd;
                beforeStart = start;
            } else {
                break;
            }
        }
        ListNode* newHead = dummy->next;
        delete(dummy);
        return newHead;
    }
};
