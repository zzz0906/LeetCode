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
            ListNode * tmp = new ListNode(current_point->val);
            N -> next = tmp;
            N = N->next;
            if (calculated == k){
                //while (N == NULL)
                N = new ListNode(0);
                Nhead = N;
            }
            current_point = current_point->next;
        }
    }
};
