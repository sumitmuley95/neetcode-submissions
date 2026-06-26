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
    int maxDiameter = INT_MIN;
    int solve(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int leftMax = solve(node->left);
        int rightMax = solve(node->right);
        maxDiameter = max(maxDiameter,leftMax+rightMax);

        return 1+max(leftMax,rightMax);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return maxDiameter;
    }
};
