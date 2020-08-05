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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        if (head->next == NULL) return;
        ListNode* start = head;
        ListNode* nextstart = head;
        while (nextstart != NULL){ 
            start = nextstart;
            ListNode* end = nextstart;
            while (end->next != NULL && end->next->next != NULL) end = end->next;
            if (start == end) break;
            nextstart = start->next;
            start->next = end->next;
            start->next->next = nextstart;
            end->next = NULL;
        }
    }
};