struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
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