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
    void dfs(TreeNode* current_node, int cur, int& height){
        height = max(cur,height);
        if (current_node -> left != NULL) dfs(current_node->left,cur+1,height);
        if (current_node -> right != NULL) dfs(current_node->right,cur+1,height);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int lh = 0;
        int rh = 0;
        if (root->left == NULL) lh = 0; else dfs(root->left,1,lh);
        if (root->right == NULL) rh = 0; else dfs(root->right,1,rh);
        return (abs(lh-rh) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};