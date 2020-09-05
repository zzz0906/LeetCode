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
class BSTIterator {
public:
    TreeNode * current;
    deque<TreeNode*> fathers;
    BSTIterator(TreeNode* root) {
        current = root;
        if (current != NULL){
            while (current->left != NULL) {
                fathers.push_back(current);
                current = current->left;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int current_answer = current->val;
        // if current is the father
        if (current->right != NULL) {
            current = current->right;
            fathers.push_back(current);
            while (current->left != NULL) {
                current = current->left;
                fathers.push_back(current);
            }
        }
        // father then it can be the right's left | not father then can be its fatehr 's point
        if (!fathers.empty()){
            current = fathers.back();
            fathers.pop_back();
        }else current = NULL;

        return current_answer;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current || !fathers.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */