/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> done_nodes;
    vector<Node*> done_new_nodes;
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        done_nodes.push_back(node);
        Node* new_node = new Node(node->val);
        done_new_nodes.push_back(new_node);
        vector<Node*> tmp;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            bool whetherfind = false;
            int index;
            for (int j = 0; j < done_nodes.size(); j++)
                if (done_nodes[j] == node->neighbors[i]){
                    index = j;
                    whetherfind = true;
                    break;
                }
            if (whetherfind == false) 
                tmp.push_back(cloneGraph(node->neighbors[i]));
            else
                tmp.push_back(done_new_nodes[index]);
        }
        new_node->neighbors = tmp;
        return new_node;
    }
};