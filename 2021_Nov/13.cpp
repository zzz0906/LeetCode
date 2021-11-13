#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct Vindex {
        int val,index;
        bool operator < (const Vindex& b) const {
            if (val == b.val) return index < b.index;
            return val < b.val;
        }
        Vindex(int val,int index){
            this->val = val;
            this->index = index;
        }
    };
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // vector<Vindex> temp;
        // for (int i = 0; i < temperatures.size(); i++) {
        //     temp.push_back(Vindex(temperatures[i], i));
        // }
        // multiset<Vindex> ms;
        // vector<int> res;
        // for (int i = temp.size() - 1; i >= 0; i--){
        //     auto it = ms.lower_bound(temp[i]);
        //     if (it == ms.end()){
        //         res.push_back(0);
        //     }else{
        //         res.push_back((*it).index);
        //     }
        // }
        // return res;
        stack<int> monotoneQ;
        vector<int> res;
        for (int i = temperatures.size() - 1; i >= 0; i--){
            while (!monotoneQ.empty() && temperatures[i] >= temperatures[monotoneQ.top()]){
                monotoneQ.pop();
            }
            if (monotoneQ.empty()){
                res.push_back(0);
                monotoneQ.push(i);
            }else{
                res.push_back(monotoneQ.top() - i);
                monotoneQ.push(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};