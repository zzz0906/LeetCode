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
    vector<vector<int>> answer;
    void dfs(TreeNode* current, vector<int> tmp, int current_value, int target){
        if (current->left == NULL && current->right == NULL){
            if (current_value+current->val == target){
                tmp.push_back(current->val);
                answer.push_back(tmp);
                return;
            }
        }else{
            tmp.push_back(current->val);
            if (current->left != NULL) dfs(current->left,tmp,current_value+current->val,target);
            if (current->right != NULL) dfs(current->right,tmp,current_value+current->val,target);
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        if (root == NULL) return answer;
        dfs(root,tmp,0,sum);
        return answer;
    }
};