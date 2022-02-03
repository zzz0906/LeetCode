class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         ostringstream os;
         serialize(root, os);
         return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }
    
    void serialize(TreeNode* root, ostringstream& os) {
        if (!root) os << "# ";
        else {
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        }
    }
    
    TreeNode* deserialize(istringstream& is) {
        string val = "";
        is >> val;
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(is);
        node->right = deserialize(is);
        return node;
    }
};