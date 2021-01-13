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
    int answer;
    void dfs(TreeNode * current, string accumulate){
        string tmp = accumulate + char(int('0') + (current->val - 0));
        if (current->right == NULL && current->left == NULL){
            answer += stoi(tmp);
            return;
        }
        else{
            if (current->right != NULL) dfs(current->right, tmp);
            if (current->left != NULL) dfs(current->left, tmp);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        answer = 0;
        dfs(root,"");
        return answer;
    }
};
