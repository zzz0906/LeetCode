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
    void dfs(TreeNode* current, vector<vector<int>> & answer, int depth){
        if (answer.size() < depth + 1){
            vector<int> tmp;
            tmp.push_back(current->val);
            answer.push_back(tmp);
        }else{
            answer[depth].push_back(current->val);
        }
        if (current->left != NULL) dfs(current->left,answer,depth+1);
        if (current->right != NULL) dfs(current->right,answer,depth+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;  
        if (root == NULL)
            return answer;
        dfs(root,answer,0);
        reverse(answer.begin(),answer.end());
        return answer;
    }
};