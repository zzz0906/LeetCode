class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *res = new Node(head->val, nullptr, nullptr);
        Node *copy_node = res, *original = head->next;
        unordered_map<Node*, Node*> m;
        m[head] = res;
        while (original) {
            Node *t = new Node(original->val, nullptr, nullptr);
            copy_node->next = t;
            m[original] = t;
            copy_node = copy_node->next;
            original = original->next;
        }
        copy_node = res; original = head;
        while (original) {
            copy_node->random = m[original->random];
            copy_node = copy_node->next;
            original = original->next;
        }
        return res;
    }
};