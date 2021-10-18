class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = 0, depthY = 0;
        bool sameParent = false;
        helper(root, x, y, 0, depthX, depthY, sameParent);
        return !sameParent && depthX == depthY;
    }
    void helper(TreeNode* node, int x, int y, int cur, int& depthX, int& depthY, bool& sameParent) {
        if (!node) return;
        if (node->val == x) depthX = cur;
        if (node->val == y) depthY = cur;
        if (node->left && node->right) {
            int left = node->left->val, right = node->right->val;
            if ((left == x && right == y) || (left == y && right == x)) sameParent = true;
        }
        helper(node->left, x, y, cur + 1, depthX, depthY, sameParent);
        helper(node->right, x, y, cur + 1, depthX, depthY, sameParent);
    }
};
