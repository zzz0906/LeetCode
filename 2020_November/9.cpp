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
    int ans;
    pair<int,int> sol(TreeNode* root){
        pair<int,int> left = make_pair(INT_MAX,INT_MIN);
        pair<int,int> right = make_pair(INT_MAX,INT_MIN);
        if (root->left != NULL)
            left = sol(root->left);
        if (root->right != NULL)
            right = sol(root->right);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        if (root->left != NULL){
            if (left.first < mini) mini = left.first;
            if (left.second > maxi) maxi = left.second;
        }
        if (root->right != NULL){
            if (right.first < mini) mini = right.first;
            if (right.second > maxi) maxi = right.second;
        }
        if (root->val < mini) mini = root->val;
        if (root->val > maxi) maxi = root->val;
        int tmp1 = abs(root->val - mini);
        int tmp2 = abs(root->val - maxi);
        if (tmp1 > ans) ans = tmp1;
        if (tmp2 > ans) ans = tmp2;
        return make_pair(mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        sol(root);
        return ans;
    }
};