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
        ListNode* bigger = new ListNode(0);
        ListNode* smaller = new ListNode(0);
        ListNode* tmp = head;
        ListNode* bigtail = bigger;
        ListNode* smatail = smaller;
        while (tmp != nullptr) {
            if (tmp->val >= x){
                bigtail->next = new ListNode(tmp->val);
                bigtail = bigtail->next;
            }
            else{
                smatail->next = new ListNode(tmp->val);
                smatail = smatail->next;
            }
            tmp = tmp->next;
        }
        smatail->next = bigger->next;
        return smaller->next;
    }
};