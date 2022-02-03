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
    vector<int> postorderTraversal(TreeNode* root) {
        deque<TreeNode*> dfs_queue;
        deque<bool> flag_queue;
        vector<int> answer;
        dfs_queue.push_back(root);
        flag_queue.push_back(true);
        TreeNode* current;
        if (root == NULL) return answer;
        while (! dfs_queue.empty()){
            TreeNode* current = dfs_queue[dfs_queue.size()-1];
            //dfs_queue.pop_back();
            if (flag_queue[flag_queue.size()-1] == false){
                answer.push_back(current->val);
                flag_queue.pop_back();
                dfs_queue.pop_back();
            }else{
                if (current->right != NULL && current->left == NULL) {flag_queue[flag_queue.size()-1] = false; dfs_queue.push_back(current->right);flag_queue.push_back(true);}
                if (current->left != NULL && current->right == NULL) {flag_queue[flag_queue.size()-1] = false; dfs_queue.push_back(current->left);flag_queue.push_back(true);}
                if (current->left != NULL && current->right != NULL){
                    flag_queue[flag_queue.size()-1] = false;
                    dfs_queue.push_back(current->right);flag_queue.push_back(true);
                    dfs_queue.push_back(current->left);flag_queue.push_back(true);
                }
                if (current->right == NULL && current->left == NULL) {flag_queue[flag_queue.size()-1] = false;}
            }
        }
        return answer;
    }
};