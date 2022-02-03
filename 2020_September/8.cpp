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
    int ans = 0;
    void dfs(TreeNode* current, string value){
        if (current->left == NULL && current->right == NULL){
            string tmp value + to_string(current->val);
            ans += strtoull(tmp.c_str(), NULL,2);
        }else
        {
            if (current->left != NULL) dfs(current->left, value+to_string(current->val));
            if (current->right != NULL) dfs(current->right, value+to_string(current->val));
        }
        
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};