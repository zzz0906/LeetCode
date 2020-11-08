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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int last = 0;
        vector<int> v1;
        vector<int> v2;
        while (l1 != NULL){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        ListNode* ans;
        int i = v1.size()-1;
        int j = v2.size()-1;
        int sum = 0;
        while (i >= 0 || j >= 0){
            if (i >= 0) {sum += v1[i]; i--;}
            if (j >= 0) {sum += v2[j]; j--;}
            ans->val = sum % 10;
            ListNode* newhead = new ListNode(sum/10); // only for the last + 1 to the new head
            newhead->next = ans;
            ans = newhead;
            sum = sum / 10;
        }
        if (ans->val != 0) return ans; else return ans->next;
    }
};