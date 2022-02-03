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
    bool dfs(TreeNode * left, TreeNode * right){
        if (left == NULL && right != NULL)
            return false;
        if (left != NULL && right == NULL)
            return false;
        if (left == NULL && right == NULL)
            return true;
        if (left->val != right->val)
            return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return dfs(root->left,root->right);
    }
};