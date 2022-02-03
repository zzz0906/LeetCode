
//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

# include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* tmp = head;
        while (tmp){
            tmp = tmp->next;
            length ++;
        }

        int splitV = ((int) length / k );
        int canInc = length - splitV*k;
        if (splitV == 0){
            splitV = 1;
            canInc = 0;
        }
        vector<ListNode*> res;
        ListNode* curHead = head;
        while (curHead){
            int target = splitV;
            if (canInc){
                target ++;
                canInc --;
            }
            ListNode* tmp = curHead;
            ListNode* last;
            while (target){
                last = tmp;
                tmp = tmp->next;
                target --;
            }
            last->next = nullptr;
            res.push_back(curHead);
            curHead = tmp;
        }
        if (res.size() < k){
            int diff = k - res.size();
            while (diff){
                res.push_back(nullptr);
                diff--;
            }
        }
        return res;
    }
};