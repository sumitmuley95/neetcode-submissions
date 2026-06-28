/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* node, priority_queue<int>& pq) {
        if(!node) return;
        pq.push(node->val);
        solve(node->left,pq);
        solve(node->right,pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>pq;
        solve(root,pq);
        if(k > pq.size()) return -1;
        int abc = pq.size() - k+1;
        cout << "pq chi size: " << pq.size() << endl;
        cout << "abc " << abc << endl;
        int val = pq.top();
        while(abc) {
            val = pq.top();
            pq.pop();
            abc--;
        }
        return val;
    }
};
