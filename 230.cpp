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
    int numth;
    int ans;
    bool flag;
    vector<int> concact(TreeNode* current){
        if (current->left == NULL && current->right == NULL){
            vector<int> tmp;
            tmp.push_back(current->val);
            if (tmp.size() >= numth){
                flag = true;
                ans = tmp[numth-1];
                return tmp;
            }
            return current;    
        }

        vector<int> tmp;
        vector<int> left;
        vector<int> right;
        if (flag) return left;
        if (current->left != NULL) left = concat(current->left);
        if (flag) return left;
        if (current->right != NULL) right = concat(current->right);
        if (flag) return left;
        left.push_back(current->val);
        left.insert(left.end(),right.begin(),right.end());
        
        if (left.size() >= numth){
            flag = true;
            ans = left[numth-1];
            return left;
        }
        return left;
    }
    int kthSmallest(TreeNode* root, int k) {
        numth = k;
        flag = false;
        concat(root);
        return ans;
    }
};