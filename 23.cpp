#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool check(vector<ListNode*>& lists){
        for (int i = 0; i < lists.size();i++)
            if (lists[i] != NULL)
                return true;
        return false;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        vector<ListNode*> current = lists;
        ListNode* answer = new ListNode(0);
        ListNode* head = answer;
        while (check(current)){
            int mini = 1000;
            int index = 0;
            for (int i = 0; i <lists.size(); i++)
                if (current[i] != NULL && current[i]->val < mini){
                    mini = current[i]->val;
                    index = i;
                }
            ListNode * tmp = new ListNode(current[index]->val);
            //printf("%d\n",current[index]->val);
            answer->next = tmp;
            answer = answer ->next;
            current[index] = current[index] -> next;
        }
        return head -> next;
    }
};
int main(){
    Solution s;
     vector<ListNode*> current;
     ListNode* p1 = new ListNode(1);
     ListNode* p1_2 = new ListNode(4);
     ListNode* p1_3 = new ListNode(4);
     p1_2->next = p1_3;
     p1->next = p1_2;
     
     ListNode* p2 = new ListNode(1);
     ListNode* p2_2 = new ListNode(3);
     ListNode* p2_3 = new ListNode(4);

     ListNode* p3 = new ListNode(2);
     ListNode* p3_2 = new ListNode(6);
     p3->next = p3_2;
     current.push_back(p1);
     current.push_back(p2);
     current.push_back(p3);
    s.mergeKLists(current);
}
