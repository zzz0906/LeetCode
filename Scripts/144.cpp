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
    vector<int> preorderTraversal(TreeNode* root) {
        deque<TreeNode*> dfs_queue;
        vector<int> answer;
        dfs_queue.push_back(root);
        TreeNode* current;
        if (root == NULL) return answer;
        while (! dfs_queue.empty()){
            TreeNode* current = dfs_queue[dfs_queue.size()-1];
            dfs_queue.pop_end();
            answer.push_back(current->val);
            if (current->right != NULL) dfs_queue.push_back(current->right);
            if (current->left != NULL) dfs_queue.push_back(current->left);
        }
        return answer;
    }
};