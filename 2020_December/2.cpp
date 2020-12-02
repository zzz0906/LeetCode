class Solution {
public:
    Solution(ListNode* head) {
        len = 0;
        ListNode *cur = head;
        this->head = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }
    }
    int getRandom() {
        int t = rand() % len;
        ListNode *cur = head;
        while (t) {
            --t;
            cur = cur->next;
        }
        return cur->val;
    }
private:
    int len;
    ListNode *head;
};