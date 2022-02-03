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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* last = head;
        ListNode* cur = head->next;
        ListNode* newnext = head->next->next;

        cur->next = last;
        last->next = newnext;
        ListNode* newhead = cur;
        ListNode* prev = last;


        while (newnext != nullptr){
            last = newnext;
            cur = newnext->next;
            if (cur == nullptr) break;
            newnext = cur->next;
            cur->next = last;
            last->next = newnext;
            prev->next = cur;
            prev = last;
        }

        return newhead;
    }
};