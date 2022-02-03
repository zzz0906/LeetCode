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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* current = head->next;
        ListNode* main_last = head;
        while (current != NULL){
            ListNode* tmp = head;
            ListNode* last = NULL;
            while (tmp->val <= current->val && tmp != current){
                last = tmp;
                tmp = tmp->next;
            }
            ListNode* next_it = current->next;
            if (tmp != current){
                //tail of the sorted list
                main_last->next = current->next;
                //insert
                if (last == NULL){
                    current->next = tmp;   // insert head
                    head = current;
                }else{
                    last->next = current;
                    current->next = tmp; // insert
                }
            }else{
                main_last = current;
            }
            current = next_it;
        }
        return head;
    }
};