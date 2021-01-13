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
    bool whetherequal;
    void dfs(TreeNode* current, int current_value, int target){
        if (current->left == NULL && current->right == NULL){
            if (current_value+current->val == target){
                whetherequal = true;
                return;
            }
        }else{
            if (current->left != NULL) dfs(current->left,current_value+current->val,target);
            if (whetherequal == true) return;
            if (current->right != NULL) dfs(current->right,current_value+current->val,target);
        }
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        whetherequal = false;
        dfs(root,0,sum);
        return whetherequal;
    }
};