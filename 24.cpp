#include<bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
  		ListNode* mid = head;
  		ListNode* newhead = NULL;
		ListNode* newmid = NULL;
  		if (head == NULL) return newhead;
  		if (head->next == NULL) return head;
  		newmid = new ListNode(head->next->val);
  		newmid->next = new ListNode(head->val);
  		newhead = newmid;
  		newmid =newmid->next;
  		mid = head->next->next;
		while(mid != NULL){
			ListNode* nn = mid->next;
			if (nn == NULL) {
				newmid->next = new ListNode(mid->val);
				break;
			} 
			newmid->next = new ListNode(nn->val);
			newmid->next->next = new ListNode(mid->val);
			newmid = newmid->next->next;
			mid = nn->next;
		}
		return newhead;
    }
};

int main(){
	ListNode* head = new ListNode(5);
	head->next = new ListNode(100);
	head->next->next = new ListNode(10);
	cout<<Solution::swapPairs(head)->next->next->val;
	
}
