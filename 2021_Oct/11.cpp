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
    int res;
    int dfs(TreeNode *cur){
        int length1 = -1,length2 = -1;
        if (cur->left != nullptr){
            length1 = dfs(cur->left);
        }
        if (cur->right != nullptr){
            length2 = dfs(cur->right);
        }
        res = max(res,length1 + length2 + 2);
        return max(length1 + 1,length2 + 1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};