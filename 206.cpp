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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newhead = NULL;
        ListNode* ans;
        ListNode* tmp = head;
        while (tmp->next != NULL){
            ListNode* last = tmp;
            tmp = tmp->next;
            while (tmp->next != NULL){
                last = tmp;
                tmp = tmp->next;
            }
            last->next = NULL;
            cout<<tmp->val<<endl;
            //find last
            if (newhead == NULL) {//start record head
                newhead = new ListNode(tmp->val); ans = newhead;
            }
            else {
                //again
                newhead->next = new ListNode(tmp->val); newhead = newhead->next;
            }

            tmp = head;
        }
        newhead->next = new ListNode(head->val);
        
        return ans;
    }
};