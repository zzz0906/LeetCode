/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp = headA;
        while (tmp != NULL) {
            ListNode* enumerate = headB;
            bool flag = false;
            while (enumerate != NULL) {
                if (enumerate == tmp){
                    return tmp;
                }
                enumerate = enumerate->next;
            }
            tmp = tmp->next;
        }
        return NULL;
    }
};