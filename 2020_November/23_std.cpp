class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return dfs(root, m);
    }
    int dfs(TreeNode *root, unordered_map<TreeNode*, int> &m) {
        if (!root) return 0;
        if (m.count(root)) return m[root];
        int val = 0;
        if (root->left) {
            val += dfs(root->left->left, m) + dfs(root->left->right, m);
        }
        if (root->right) {
            val += dfs(root->right->left, m) + dfs(root->right->right, m);
        }
        val = max(val + root->val, dfs(root->left, m) + dfs(root->right, m));
        m[root] = val;
        return val;
    }
};