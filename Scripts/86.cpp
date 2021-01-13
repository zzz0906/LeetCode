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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesstmp = NULL;
        ListNode* moretmp = NULL;
        ListNode* tmp = head;
        ListNode* ltmphead = NULL;
        ListNode* mtmphead = NULL;
        bool le = false;
        bool me = false;
        if (head == NULL)
            return head;
        while (tmp != NULL){
            if (tmp->val < x){
                if (le == false){
                    lesstmp = new ListNode(tmp->val);
                    le = true;
                    ltmphead = lesstmp;
                }else{
                    lesstmp->next = new ListNode(tmp->val);
                    lesstmp = lesstmp->next;
                }
            }else{
                if (me == false){
                    moretmp = new ListNode(tmp->val);
                    me = true;
                    mtmphead = moretmp;
                }else{
                    moretmp->next = new ListNode(tmp->val);
                    moretmp = moretmp->next;
                }
            }
            tmp = tmp->next;
        }
        if (le == false)
            return mtmphead;
        lesstmp->next = mtmphead;
        return ltmphead;
    }
};