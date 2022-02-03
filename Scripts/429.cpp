/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> res;
    void dfs(Node* cur, int level){
        if (res.size() < level + 1){
            vector<int> tmp;
            tmp.push_back(cur->val);
            res.push_back(tmp);
        }else{
            res[level].push_back(cur->val);
        }
        for (auto child : cur->children){
            dfs(child,level+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        res.clear();
        if (!root){
            return res;
        }
        dfs(root,0);
        return res;
    }
};