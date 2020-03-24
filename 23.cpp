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
        vector<int> points;
        vector<ListNode*> current = lists;
        for (int i = 0; i < lists.size(); i++)
            points.push_back(0);
        ListNode* answer;
        ListNode* head;
        while (check(current)){
            int mini = 10000000;
            int index = 0;
            for (int i = 0; i <lists.size(); i++)
                if (current[i] != NULL && current[i]->val < mini){
                    mini = current[i]->val;
                    index = i;
                }
            ListNode * tmp = new ListNode(current[index]->val);
            printf("%d\n",current[index]->val);
            if (answer == NULL){
                answer = tmp;
                head = answer;
            }else{
                answer->next = tmp;
                answer = answer->next;
            }
            current[index] = current[index] -> next;
        }
        return head;
    }
};
int main(){
    Solution s;
     vector<ListNode*> current;
     ListNode* p1 = new ListNode(2);
     ListNode* p1_2 = new ListNode(4);
     p1->next = p1_2;
     ListNode* p2 = new ListNode(3);
     current.push_back(p1);
     current.push_back(p2);
    s.mergeKLists(current);
}
