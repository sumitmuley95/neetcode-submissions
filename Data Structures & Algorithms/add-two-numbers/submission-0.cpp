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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && l2) return l2;
        if (l1 && !l2) return l1;
        if (!l1 && !l2) return l1;

        ListNode* num1 = l1;
        ListNode* num2 = l2;

        int carry = 0;

        ListNode head(0);
        ListNode* curr = &head;
        while (num1 && num2) {
            int sum = num1->val + num2->val + carry;
            if (sum >= 10) {
                curr->next = new ListNode(sum % 10);
                carry = 1;
            } else {
                curr->next = new ListNode(sum);
                carry = 0;
            }
            curr = curr->next;
            num1 = num1->next;
            num2 = num2->next;
        }
        // ithe aala aahe mhanje maybe koni ajun asan check kar ekda
        while (num1) {
            int sum = num1->val + carry;
            if (sum >= 10) {
                curr->next = new ListNode(sum % 10);
                carry = 1;
            } else {
                curr->next = new ListNode(sum);
                carry = 0;
            }
            curr = curr->next;
            num1 = num1->next;
        }
        while (num2) {
            int sum = num2->val + carry;
            if (sum >= 10) {
                curr->next = new ListNode(sum % 10);
                carry = 1;
            } else {
                curr->next = new ListNode(sum);
                carry = 0;
            }
            curr = curr->next;
            num2 = num2->next;
        }

        if(carry > 0) curr->next = new ListNode(carry);

        return head.next;
    }
};
