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
    void solve(TreeNode* node, int k, int& count, int& result) {
        //base case 
        if(!node || result != -1) return;
        solve(node->left,k,count,result);
        count++;
        if(count == k) {
            result = node->val;
            return;
        }
        solve(node->right,k,count,result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        int count = 0;
        solve(root,k,count,result);
        return result;
    }
};
