#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto comp = [](const ListNode* lhs, const ListNode* rhs) {return lhs->val > rhs->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
		for (auto p : lists)
			if (p)
				q.push(p);
		if (q.empty()) return nullptr;

		ListNode* head = q.top();
		q.pop();
		if (head->next)
			q.push(head->next);
		ListNode* p = head;
		while (!q.empty()) {
			p->next = q.top();
			q.pop();
			p = p->next;
			if (p->next) q.push(p->next);
		}
		return head;
	}
};
