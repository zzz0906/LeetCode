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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        if (preorder.size() == 1){
            return new TreeNode(preorder[0]);
        }
        int split = 0;
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] == preorder[0]){
                split = i;
                break;
            }
        }
        vector<int>::const_iterator tmpf1 = inorder.begin();
        vector<int>::const_iterator tmpe1 = inorder.begin() + split;
        vector<int> leftinorder(tmpf1,tmpe1);
        vector<int>::const_iterator tmpf2 = inorder.begin() + split + 1;
        vector<int>::const_iterator tmpe2 = inorder.end();
        vector<int> rightinorder(tmpf2,tmpe2);
        vector<int>::const_iterator tmpf3 = preorder.begin()+1;
        vector<int>::const_iterator tmpe3 = preorder.begin() + split + 1;
        vector<int> leftpreorder(tmpf3,tmpe3);
        vector<int>::const_iterator tmpf4 = preorder.begin() + split + 1;
        vector<int>::const_iterator tmpe4 = preorder.end();
        vector<int> rightpreorder(tmpf4,tmpe4);
        TreeNode* root = new TreeNode(preorder[0],buildTree(leftpreorder,leftinorder),buildTree(rightpreorder,rightinorder));
        return root;
    }
};