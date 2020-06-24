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
    void dfs(TreeNode* current, int depth){
        if (depth > answer)
            answer = depth;
        if (current->right != NULL) dfs(current->right,depth+1);
        if (current->left != NULL) dfs(current->left,depth+1);
    }
    int maxDepth(TreeNode* root) {
        answer = 0;
        if (root == NULL)
            return 0;
        dfs(root,1);
        return answer;
    }
};