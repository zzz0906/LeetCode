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
    long long sum;
    long long res;
    void calSum(TreeNode* cur){
        sum += cur->val;
        if (cur->left){
            calSum(cur->left);
        }
        if (cur->right){
            calSum(cur->right);
        }
    }
    int split(TreeNode* father){
        int left = 0, right = 0;
        if (father->left){
            left = split(father->left);
            res = max(res, (sum - left) * left);
        }
        if (father->right){
            right = split(father->right);
            res = max(res, (sum - right) * right);
        }   
        return left + right + father->val; 
    }
    int maxProduct(TreeNode* root) {
        sum = 0;
        res = LONG_MIN;
        calSum(root);
        split(root);
        cout << res << endl;
        return res % (long long)(pow(10,9) + 7);
    }
};