/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = head;
        if (head == NULL) return NULL;
        if (head -> next == NULL){
            if (head->val == val) return NULL;
            else return head;
        }
        while (current != NULL && current -> val == val)
            current = current -> next;
        ListNode* ans;
        
        if (current == NULL) return NULL;
        else ans = current;
        ListNode* last = ans;
        current = last -> next;

        while (current != NULL) {
            if (current->val == val) {
                last->next = current->next;
                current = last->next;
            }else{
                last = current;
                current = current -> next;
            }
        }
        return ans;
    }
};