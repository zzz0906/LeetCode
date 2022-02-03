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
    int depth(TreeNode* cur, int max_depth){
        if (cur == nullptr) return max_depth;
        return max(depth(cur->left,max_depth + 1), depth(cur->right,max_depth + 1));
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        bool flag = false;
        if (abs(depth(root->left,0) - depth(root->right,0)) <= 1) flag = true;
        return flag && isBalanced(root->right) && isBalanced(root->left);
    }
};