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
    int res;
    void dfs(vector<int> records, int target, TreeNode* cur){
        if (cur == nullptr) return;
        for (auto &record : records) {
            record += cur->val;
            if (record == target) {
                res++;
                //cout << cur->val << endl;
            }
            //cout << record;
        }
        //cout << endl;
        records.push_back(cur->val);
        if (cur->val == target){
            res++;
        }
        if (cur->left){
            dfs(records, target, cur->left);
        }
        if (cur->right){
            dfs(records, target, cur->right);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        res = 0;
        vector<int> tmp;
        dfs(tmp, targetSum, root);

        return res;
    }
};