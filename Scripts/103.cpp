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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // vector<vector<int>> answer;  
        // if (root == NULL)
        //     return answer;
        // queue<TreeNode*> bfs;
        // bfs.push(root);
        // int depth = 0;
        // int count = 0;
        // while (!bfs.empty()) {
        //     TreeNode* current = bfs.pop();
        //     count ++;
        //     if (count > (pow(2,depth+1)-1)){
        //         depth ++;
        //     }
        //     if (answer.size() < depth + 1){
        //         vector<int> tmp;
        //         tmp.push_back(current->val);
        //         answer.push_back(tmp);
        //     }else{
        //     answer[depth].push_back(current->val);
        //     }

        // }
        // return answer;
        vector<vector<int>> answer;  
        if (root == NULL)
            return answer;
        dfs(root,answer,0);
        for (int i = 0; i < answer.size();i++)
            if (i % 2 == 1)
                reverse(answer[i].begin(),answer[i].end());
        return answer;
    }
};