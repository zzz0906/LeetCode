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
    ListNode* oddEvenList(ListNode* head) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp){
            len ++;
            tmp = tmp->next;
        }
        ListNode* odd_tail;
        if (len % 2 == 0){
            //1 2 3 4
            int coun = 1;
            odd_tail = head;
            while (coun < len - 1){
                odd_tail = odd_tail->next;
                coun ++;
            }
        }else{
            int coun = 1;
            odd_tail = head;
            while (coun < len){
                odd_tail = odd_tail->next;
                coun ++;
            }
        }
        int st = 1;
        ListNode* last;
        ListNode* cur = head;
        while (st <= len){
            if (st % 2 == 0){
                st += 1;
                odd_tail->next = cur;
                last->next = cur->next;
                cur = cur->next;
            }else{
                st += 1;
                last = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};