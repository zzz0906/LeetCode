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
		int size1,size2; 
		vector<int> a1;
		vector<int> a2;        
		size1 = 0;
		ListNode* mid = l1;
		while(mid != NULL){
			a1.push_back(mid->val);
			size1++;
			mid = mid->next; 
		}
		size2 = 0; mid = l2;
		while(mid != NULL){
			a2.push_back(mid->val);
			size2++;
			mid = mid->next;
		}
		int size = min(size1,size2);
		int maxx = max(size1,size2);
		for (int j = 0;j<maxx-size1;j++)
			a1.push_back(0);
		for (int j = 0;j<maxx-size2;j++)
			a2.push_back(0);
		vector<int> answer;
		int next = 0;
		for (int i = 0;i<maxx;i++){
			int midd = a1[i]+a2[i]+next;
			next = midd / 10;
			midd = midd % 10;
			answer.push_back(midd);
		} 
		if (next != 0) answer.push_back(next);
		ListNode* realanswer = new ListNode(answer[0]);
		ListNode* mm = realanswer;
		for (int i = 1;i<answer.size();i++)
			{
				mm->next =new ListNode(answer[i]);
				mm = mm->next;
			}
		return realanswer;
    }
};
