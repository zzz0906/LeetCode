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
        int last;
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;
        ListNode* tmp = head->next;
        ListNode* lasttmp = head;
        ListNode* back;
        while (tmp->val == lasttmp->val){
            while (tmp != NULL && tmp->val == lasttmp->val) {
                tmp = tmp->next;
            }
            head = tmp;
            if (head == NULL) return head;
            if (head->next == NULL) return head;
            lasttmp = head;
            tmp = lasttmp->next;
        }
        // repeat in the head
        if (tmp -> next == NULL)
            return head;
        back = lasttmp;
        lasttmp = tmp;
        tmp = tmp -> next;
        // if do not exist duplicates we need to move on until we find the duplicates
        while (tmp->val != lasttmp->val){
            back = lasttmp;
            lasttmp = tmp;
            tmp = tmp->next;
            if (tmp == NULL)
                return head;
        }
        while (tmp->next != NULL) {
            if (tmp->val == lasttmp->val) {
                tmp = tmp->next;
                // SOLVE the duplicates
            }else{
                back->next = tmp;
                lasttmp = tmp;
                tmp = tmp->next;
                // find next duplicates ones
                while (tmp->val != lasttmp->val){
                    back = lasttmp;
                    lasttmp = tmp;
                    tmp = tmp->next;
                    if (tmp == NULL)
                        return head;
                }
            }
        }
        // to the end
        if (tmp->val == lasttmp->val){
            back->next = tmp->next;
        }else{
            back->next = tmp;
        }
        return head;
    }
};