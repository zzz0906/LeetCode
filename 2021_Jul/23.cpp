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
    bool dfs(TreeNode* root){
        if (root == nullptr){
            return false;
        }
        bool leftDel = dfs(root->left);
        bool rightDel = dfs(root->right);
        bool notDelete =  (root->val == 1) || leftDel || rightDel;
        if (notDelete){
            if (leftDel == false){
                root->left == nullptr;
            }
            if (rightDel == false){
                root->right == nullptr;
            }
        }
        return notDelete;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool fin = dfs(root);
        if (!fin){
            return nullptr;
        }
    }
};