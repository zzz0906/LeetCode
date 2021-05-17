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
    void dfs(TreeNode* cur, int deep){
        if (cur == nullptr)
            return;
        if (deep % 2 == 0)
            res += 1;
        dfs(cur->left,deep + 1);
        dfs(cur->right,deep + 1);
    }
    int minCameraCover(TreeNode* root) {
        res = 0;
        dfs(root,1);
        if (res == 0)
            return 1;
        else
            return res;
    }
};