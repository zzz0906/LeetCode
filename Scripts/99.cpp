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
    vector<TreeNode*> Nodelist;
    void dfs(TreeNode * current_node){
        if (current_node->left != NULL)
            dfs(current_node->left);
        Nodelist.push_back(current_node);
        answer.push_back(current_node->val);
        if (current_node->right != NULL)
            dfs(current_node->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(answer.begin(), answer.end());
        for (int i = 0; i < Nodelist.size();i++)
            Nodelist[i]->val = answer[i];
    }
};