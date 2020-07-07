class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        if (root->left){
            if (root->right) {
                root->left->next = root->right;
                Node* tmp = root->next;
                while (tmp != NULL && (tmp->left == NULL || tmp->right == NULL)) tmp = tmp->next;
                if (tmp){
                    if (tmp->left == NULL)
                        root->right->next = tmp->right;
                    else
                        root->right->next = tmp->left;
                }
                else root->right->next = NULL;
            }else{
                Node* tmp = root->next;
                while (tmp != NULL && (tmp->left == NULL || tmp->right == NULL)) tmp = tmp->next;
                if (tmp){
                    if (tmp->left == NULL)
                        root->left->next = tmp->right;
                    else
                        root->left->next = tmp->left;
                }
                else root->left->next = NULL;
            }
        } if (root->right){
            Node* tmp = root->next;
            while (tmp != NULL && (tmp->left == NULL || tmp->right == NULL)) tmp = tmp->next;
            if (tmp){
                if (tmp->left == NULL)
                    root->right->next = tmp->right;
                else
                    root->right->next = tmp->left;
            }
            else root->right->next = NULL;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};