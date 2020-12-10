#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * N = new ListNode(0);
        ListNode * Nhead = N;
        ListNode * answer = new ListNode(0);
        ListNode * answerhead = answer;
        ListNode *current_point = head;
        int calculated = 0;
        while (current_point != NULL) {
            calculated ++;
            //cout<<current_point->val<<endl;
            ListNode * tmp = new ListNode(current_point->val);
            N -> next = tmp;
            N = N->next;
            if (calculated == k){ 
                ListNode * headtmp = Nhead;
                while (headtmp -> next != NULL){
                    ListNode * ttmp = Nhead;
                    while (ttmp -> next -> next != NULL)
                        ttmp = ttmp -> next;
                    answer->next = new ListNode(ttmp ->next->val);
                    answer = answer->next;
                    ttmp->next = NULL;
                }
                N = new ListNode(0);
                Nhead = N;
                calculated = 0;
            }
            if (current_point -> next == NULL) {
                ListNode * headtmp = Nhead;
                headtmp = headtmp->next;
                while (headtmp != NULL){
                    ListNode * anstmp = new ListNode(headtmp->val);
                    answer->next = anstmp;
                    answer = answer->next;
                    headtmp = headtmp->next;
                }
                break;
            }
            current_point = current_point->next;
        }
        return answerhead->next;
    }
};
int main(){
    ListNode * test = new ListNode(1);
    ListNode * header = test;
    ListNode * tmp = new ListNode(2);
    test->next = tmp;
    test =test->next;
    tmp = new ListNode(3);
    test->next = tmp;
    test =test->next;
    tmp = new ListNode(4);
    test->next = tmp;
    test =test->next;
    tmp = new ListNode(5);
    test->next = tmp;
    test =test->next;

    Solution s;
    s.reverseKGroup(header,2);
}