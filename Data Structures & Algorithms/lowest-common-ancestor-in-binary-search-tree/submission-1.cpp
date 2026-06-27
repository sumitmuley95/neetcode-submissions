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
    void solve(TreeNode* node, vector<TreeNode*>& path, TreeNode* target) {
        if(!node) return;
        path.push_back(node);
        if(target == node) return;
        else if(node->val < target->val) solve(node->right,path,target);
        else if(node->val > target->val) solve(node->left,path,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>leftPath;
        vector<TreeNode*>rightPath;
        solve(root,leftPath,p);
        solve(root,rightPath,q);
        TreeNode* commonTillNow = nullptr;
        for(int i = 0; i < leftPath.size() && i < rightPath.size(); i++) {
            if(leftPath[i] == rightPath[i]) commonTillNow = leftPath[i];
            else break;
        }
        return commonTillNow;
    }
};
