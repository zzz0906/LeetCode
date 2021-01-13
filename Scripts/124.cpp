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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* node, int& res){
        if (!node) return;
        int left = max(dfs(node->left, res), 0);
        int right = max(dfs(node->right, res), 0);
        res = max(res,left + right + node->val);
        return max(left,right) + node->val;
    }
};