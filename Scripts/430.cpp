/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* tmp = head;
        
        while (tmp){
            if (tmp->child){
                Node* reserveNext = tmp->next;
                
                Node* last = flatten(tmp->child);
                while (last->next)
                    last = last->next;
                
                tmp->next = tmp->child;
                tmp->child->prev = tmp;
                tmp->child = nullptr;
                
                last->next = reserveNext;
                if (reserveNext){
                    reserveNext->prev = last;
                }

                tmp = reserveNext;
                
            } else{
                
                tmp = tmp->next;
            }
        }
        
        return head;
    }
};