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
    int getDecimalValue(ListNode* head) {
        ListNode* tmp = head;
        int k = 0;
        int exp = 1;
        while (tmp != NULL){
            k = k + 1;
            tmp = tmp->next;
        }
        for (int i = 1; i <= k - 1; i++){
            exp = exp * 2;
        }
        tmp = head;
        int ans = 0;
        while (tmp != NULL){
            ans = ans + (tmp->val)*exp;
            exp /= 2;
            tmp = tmp -> next;
        }
    }
};