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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* i = list1;
        ListNode* j = list2;

        ListNode* list3 = nullptr;
        ListNode* head = nullptr;

        while(i && j) {
            ListNode* nextVal = nullptr;
            if(list3 == nullptr) {
                if(i->val < j->val) {
                    head = i;
                    list3 = head;
                    i = i->next;
                    list3->next = nullptr;
                } else {
                    head = j;
                    list3 = head;
                    j = j->next;
                    list3->next = nullptr;
                }
            }
            else if(i->val < j->val) {
                nextVal = i;
                i = i->next;
                nextVal->next = nullptr;
                list3->next = nextVal;
                list3 = nextVal;
                
            } else {
                nextVal = j;
                j = j->next;
                nextVal->next = nullptr;
                list3->next = nextVal;
                list3 = nextVal;
            }
        }
        //remaining elements la add kar
        //konta tari ek list out of bound zali aahe 
        if(i) {
            while(i) {
                ListNode* nextVal = nullptr;
                nextVal = i;
                i = i->next;
                nextVal->next = nullptr;
                list3->next = nextVal;
                list3 = nextVal;
            }
        } else if(j) {
            while(j) {
                ListNode* nextVal = nullptr;
                nextVal = j;
                j = j->next;
                nextVal->next = nullptr;
                list3->next = nextVal;
                list3 = nextVal;
            }
        }
        return head;
    }
};
