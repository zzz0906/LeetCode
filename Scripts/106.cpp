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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0)
            return NULL;
        if (postorder.size() == 1){
            return new TreeNode(postorder[postorder.size()-1]);
        }
        int split = 0;
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] == postorder[postorder.size()-1]){
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
        vector<int>::const_iterator tmpf3 = postorder.begin();
        vector<int>::const_iterator tmpe3 = postorder.begin() + split;
        vector<int> leftpostorder(tmpf3,tmpe3);
        vector<int>::const_iterator tmpf4 = postorder.begin() + split;
        vector<int>::const_iterator tmpe4 = postorder.end()-1;
        vector<int> rightpostorder(tmpf4,tmpe4);
        TreeNode* root = new TreeNode(postorder[postorder.size()-1],buildTree(leftinorder,leftpostorder),buildTree(rightinorder,rightpostorder));
        return root;
    }
};