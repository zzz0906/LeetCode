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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *, bool> visited;
        ListNode * tmp = head;
        while (tmp != NULL) {
            if (visited.count(tmp))
                return tmp;
            visited[tmp] = true;
            tmp = tmp->next;
        }
        return NULL;
    }
};