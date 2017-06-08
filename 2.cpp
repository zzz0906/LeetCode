#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int size1£¬size2; 
		vector<int> answer;
		vector<int> a1;
		vector<int> a2;        
		size1 = 0;
		ListNode* mid = l1;
		while(mid != NULL){
			size1++;
			mid = mid->next;
		}
		size2 = 0; mid = l2;
		while(mid != NULL){
			size2++;
			mid = mid->next;
		}
		int size = max(size1,size2);
		for (int i = 0;i<size;i++){
			
		} 
    }
};
