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
    int solve(TreeNode* root){
        if (root == NULL) return 0;
        int left = 0;
        int right = 0;
        left = solve(root->left);
        right = solve(root->right);
        ans += abs(left - right);
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};