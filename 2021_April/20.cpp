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
    vector<int> preorder(Node* root) {
        vector<int> tmp;
        if (root == NULL)
            return tmp;
        tmp.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            vector<int> ch = preorder(root->children[i]);
            for (int j = 0; j < ch.size(); j++)
                tmp.push_back(ch[j]);
        }
        return tmp;
    }
};