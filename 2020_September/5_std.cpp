class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {    
    function<void(TreeNode*, vector<int>&)> inorder = [&](TreeNode* root, vector<int>& t) {
      if (!root) return;
      inorder(root->left, t);
      t.push_back(root->val);
      inorder(root->right, t);
    };
    vector<int> t1;
    vector<int> t2;
    inorder(root1, t1);
    inorder(root2, t2);
    vector<int> m;
    std::merge(begin(t1), end(t1), begin(t2), end(t2), back_inserter(m));    
    return m;
  }
};