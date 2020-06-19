class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end) {
        // if (start == end) {
        //     vector<TreeNode*> res;
        //     TreeNode *node = new TreeNode(i);
        //     res.push_back(node);
        //     return res;
        // };
        // for (int i = start+1; i <= end; ++i) {
        //     // 5-6 => 5-5 6-6 
        //     // 1-10 => 1,1  2,10 i=2; i=3 1,2 3,10; ... i=10 1..9, 10..10
        //     // OH!!! That's not correct, there is no null          
        //     auto left = helper(start, i - 1), right = helper(i, end);
        //     for (auto a : left) {
        //         for (auto b : right) {
        //             TreeNode *node = new TreeNode(i);
        //             node->left = a;
        //             node->right = b;
        //             res.push_back(node);
        //         }
        //     }
        // }
        if (start > end) return {nullptr};
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            //cout<<i<<endl; It seems to do not contains the 
            // remember we must put a node as root current node
            auto left = helper(start, i - 1), right = helper(i + 1, end);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};