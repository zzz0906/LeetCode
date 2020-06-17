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
    vector<int> answer;
    void dfs(TreeNode * current_node){
        if (current_node->right != NULL)
            dfs(current_node->right);
        answer.push_back(current_node->val);
        if (current_node->left != NULL)
            dfs(current_node->left);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return answer;
    }
};