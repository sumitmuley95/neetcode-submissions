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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* it = dummy;
        vector<int>values;
        for(auto list : lists) {
            while(list) {
                values.push_back(list->val);
                list = list->next;
            }
        }
        sort(values.begin(),values.end());
        for(int i = 0; i < values.size(); i++) {
            it->next = new ListNode(values[i]);
            it = it->next;
        }
        return dummy->next;
    }
};
