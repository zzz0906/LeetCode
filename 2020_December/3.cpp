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
    TreeNode* increasingBST(TreeNode* root) {
        deque<TreeNode*> q;
        TreeNode* res = new TreeNode(-1);
        TreeNode* ans = res;
        TreeNode* cur = root;
        while (cur || !q.empty()){
            while (cur){
                q.push_back(cur);
                cur = cur->left;
            }
            cur = q.back(); q.pop_back();
            ans->right = cur;
            ans = ans->right;
            cur->left = nullptr;
            cur = cur->right;
        }
        return res->right;
        //return nullptr;
    }
};