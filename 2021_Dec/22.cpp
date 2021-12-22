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
    ListNode * middle( ListNode *h){
        auto slow = h , fast = h->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode * reverse(ListNode *h){
        if(!h || !h->next) return h;
        
        auto tail = h->next;
        auto ans = reverse(tail);
        
        tail->next = h;
        h->next = nullptr;
        
        return ans;   
    }
    
    void reorderList(ListNode* head) {
        auto midBefore = middle(head);
        auto midAfter = midBefore -> next;
        midBefore->next = NULL;
        midAfter = reverse(midAfter);
        
        auto a = head , b = midAfter;
        while(b){
            auto nxt1=a->next;
            auto nxt2=b->next;
            a->next=b, b->next=nxt1;
            b=nxt2, a=nxt1;
        }
        return ;
    }
};