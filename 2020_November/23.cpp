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
    int ans;
    int dfs(TreeNode* current,int index){
        if (index % 2 == 1) ans += current->val;
        if (current->left != NULL) dfs(current->left,index+1);
        if (current->right != NULL) dfs(current->right,index+1);
    }
    int rob(TreeNode* root) {
        ans = 0;
        dfs(root,1);
        int res = ans;
        dfs(root,0);
        if ()
    }
};