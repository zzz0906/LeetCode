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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);
        int mid = (nums.size())/2;
        TreeNode* answer = new TreeNode(nums[mid]);
        auto first = nums.begin();
        auto last = nums.begin() + mid;
        vector<int> left(first, last);
        first = nums.begin()+mid+1;
        last = nums.end();
        vector<int> right(first, last);
        answer->left = sortedArrayToBST(left);
        answer->right = sortedArrayToBST(right);
        return answer;
    }
};