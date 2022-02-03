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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* res = nullptr;
        if (preorder.size() == 0){
            return res;
        }
        res = new TreeNode(preorder[0]);
        if (preorder.size() == 1){
            return res;
        }

        int root = preorder[0];

        vector<int> left;
        int i = 1;
        for (i = 1; i < preorder.size(); i++)
            if (preorder[i] > preorder[0]){
                break;
            }else{
                left.push_back(preorder[i]);
            }
        
        res->left = bstFromPreorder(left);
        vector<int> right;
        for (int j = i; j < preorder.size(); j++){
            right.push_back(preorder[j]);
        }
        res->right = bstFromPreorder(right);
        return res;
    }
};