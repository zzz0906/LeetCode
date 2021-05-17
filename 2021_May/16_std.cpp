class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        return (helper(root, res) < 1 ? 1 : 0) + res;
    }
    // Return 0 if leaf, 1 if parent of leaf with camera on this node, 2 if covered without camera on this node.
    int helper(TreeNode* node, int& res) {
        if (!node) return 2;
        int left = helper(node->left, res), right = helper(node->right, res);
        if (left == 0 || right == 0) {
            ++res;
            return 1;
        }
        return (left == 1 || right == 1) ? 2 : 0;
    }
};