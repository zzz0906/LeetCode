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
    bool checkleft(TreeNode * current,int val){
        if (current == NULL) return true; 
        return current->val < val && checkleft(current->left,val) && checkleft(current->right,val);
    }
    bool checkright(TreeNode * current,int val){
        if (current == NULL) return true; 
        return current->val > val && checkleft(current->left,val) && checkleft(current->right,val);   
    }
    bool isValidBST(TreeNode* root) { 
        if (root == NULL)
                return true;
        return checkleft(root->left,root->val) && checkright(root->right,root->val) && isValidBST(root->left) && isValidBST(root->right);
    } 
};