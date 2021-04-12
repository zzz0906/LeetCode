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
    int max_depth;
    int sum;
    void dfs(TreeNode * cur, int cur_depth){
        if (cur_depth > max_depth) {
            max_depth = cur_depth;
            sum = cur->val;
        } else if (cur_depth == max_depth) 
            sum += cur->val;
        if (cur->left) dfs(cur->left, cur_depth + 1);
        if (cur->right) dfs(cur->right, cur_depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        max_depth  = 0;
        sum = 0;
        dfs(root,1);
        return sum;
    }   
};