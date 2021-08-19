//Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int res;
    void dfs(TreeNode* cur, int maximum){
        if (cur->val >= maximum)
            res ++;
        if (cur->left)
            dfs(cur->left, max(maximum,cur->val));
        if (cur->right)
            dfs(cur->right, max(maximum,cur->val));
    }
    int goodNodes(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};