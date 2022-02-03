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
    void flatten(TreeNode* root) {
        while (root) {
        auto left = root->left;
        if (left) {
            auto tmp = left;
            while (tmp->right) tmp = tmp->right;
            tmp->right = root->right;
            root->right = left;
            root->left = nullptr;
        }
        root = root->right;
        }
    }
};