  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * lasttmp = head;
        if (head == NULL)
            return head;
        ListNode * tmp = head->next;
        if (tmp == NULL)
            return head;
        while (tmp->next != NULL) {
            if (lasttmp->val != tmp->val) {
                lasttmp->next = tmp;
                lasttmp = tmp;
            }
            tmp = tmp->next;
        }
        if (tmp->val == lasttmp->val){
            lasttmp->next = tmp->next;
        }else{
           lasttmp->next = tmp;
        }
        return head;
    }
};