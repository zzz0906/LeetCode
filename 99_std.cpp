// Now O(1) space complexity
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *cur = root, *pre = nullptr ;
        while (cur) {
            if (cur->left){
                TreeNode *p = cur->left;
                while (p->right && p->right != cur) p = p->right;
                if (!p->right) {
                    p->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    p->right = NULL;
                }  
            }
            if (pre && cur->val < pre->val){
              if (!first) first = pre;
              second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};