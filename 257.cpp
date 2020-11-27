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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> l;
        vector<string> r;
        vector<string> res;
        if (root == NULL) return res;
        if (root -> left == NULL && root -> right == NULL){
            res.push_back(to_string(root -> val));
            return res;
        }
        if (root->left != NULL)
            l = binaryTreePaths(root->left);
        if (root->right != NULL)
            r = binaryTreePaths(root->right);
        string cur = to_string(root->val);
        for (string s : l){
            res.push_back(cur + "->" + s);
        }
        for (string s : r){
            res.push_back(cur + "->" + s);
        }
        return res;
    }
};