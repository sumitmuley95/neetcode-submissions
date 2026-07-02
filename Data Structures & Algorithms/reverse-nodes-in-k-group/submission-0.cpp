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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        if(k == 0 || k == 1) return head;
        vector<int>nums;
        ListNode* it = head;
        while(it) {
            nums.push_back(it->val);
            it = it->next;
        }

        for(int i = 0; i < nums.size();) {
            if(i+k > nums.size()) break;
            reverse(nums.begin()+i,nums.begin()+(i+k));
            i = i+k;
        }

        ListNode* dummy = new ListNode(-1);
        it = dummy;
        for(auto i : nums) {
            it->next = new ListNode(i);
            it = it->next;
        }
        return dummy->next;
    }
};
