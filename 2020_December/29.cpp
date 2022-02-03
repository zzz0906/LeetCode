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
    int dfs(TreeNode* current, int oddNum, unordered_map<int,bool> isOdd){
        oddNum += isOdd[current->val] ? -1 : 1;

        if (current->left == nullptr && current->right == nullptr) {
            return oddNum <= 1 ? 1 : 0;
        }

        isOdd[current->val] = !isOdd[current->val];
        int leftCount = current->left != nullptr ? dfs(current->left, oddNum, isOdd) : 0;
        int rightCount = current->right != nullptr ? dfs(current->right, oddNum, isOdd) : 0;
        isOdd[current->val] = !isOdd[current->val];

        return leftCount + rightCount;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,bool> isOdd;
        for (int i = 0; i < 10; i++)
            isOdd[i] = false;
        return dfs(root,0,isOdd);
    }
};