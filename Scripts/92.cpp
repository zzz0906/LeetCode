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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode * tmphead;
        ListNode * beforem;
        ListNode * reversetmphead;
        ListNode * reversetmptale;
        if (head->next == NULL)
            return head;
        if (head == NULL)
            return head;
        int count = 2;
        if (m == 1){
            reversetmphead = head;
            reversetmptale = head;
            tmphead = head;
            count = 2;
            while (count <= n){
                ListNode * tmp = new ListNode(tmphead->next->val,reversetmphead);
                reversetmphead = tmp;
                tmphead = tmphead->next;
                count++;
            }
            reversetmptale->next = tmphead->next;
            return reversetmphead;
        }else{
            ListNode * tmp = head;
            while (count <= m-1){
                tmp = tmp->next;
                count++;
            }
            beforem = tmp;
            tmp = tmp->next;
            reversetmphead = tmp;
            reversetmptale = tmp;
            ListNode * tmpoftmp = tmp;
            count++;
            while (count <= n){
                ListNode * tmp = new ListNode(tmpoftmp->next->val,reversetmphead);
                reversetmphead = tmp;
                tmpoftmp = tmpoftmp->next;
                count++;
            }
            beforem->next = reversetmphead;
            reversetmptale->next = tmpoftmp->next;
            return head;
        }
    }
};