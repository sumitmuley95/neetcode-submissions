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
    int countMax = INT_MIN;
    int solve(TreeNode* node, int count) {
        if(!node) {
            countMax = max(countMax,count);
            return countMax;
        }
        solve(node->left, count+1);
        solve(node->right, count+1);
        return countMax;
    }
    int maxDepth(TreeNode* root) {
        int count = 0;
        return solve(root,count);
    }
};
