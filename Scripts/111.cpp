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
    void dfs(TreeNode* current_node, int cur, int& height){
        if (current_node->right == NULL && current_node->left == NULL) height = min(cur,height);
        if (current_node -> left != NULL) dfs(current_node->left,cur+1,height);
        if (current_node -> right != NULL) dfs(current_node->right,cur+1,height);
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int answer;
        dfs(root,1,answer);
        return answer;
    }
};