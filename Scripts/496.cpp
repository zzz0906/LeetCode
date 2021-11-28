# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // map value to index
        unordered_map<int, int> v2index;
        // Monotonic Queue only store value with close index
        stack<int> mQ;
        // the greater index of current element (becaue we run MQ reversely so the answer index will be reverse too)
        vector<int> greaterRes;
        for (int i = nums2.size() - 1; i >= 0; i--){
            // map value to index
            v2index[nums2[i]] = i;
            // pop out past value unitl find a bigger one
            while (!mQ.empty() && nums2[mQ.top()] < nums2[i]){
                mQ.pop();
            }
            
            if (mQ.empty()){
                // nothing
                greaterRes.push_back(-1);
            }else{
                //a bigger element
                greaterRes.push_back(mQ.top());
            }
            // push current element
            mQ.push(i);
        }
        
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++){
            // greaterRes is reverse. the first element store the greater index of the last element.
            int index = greaterRes[nums2.size() - 1 - v2index[nums1[i]]];
            // -1 means no element
            res.push_back(index == -1 ? -1 : nums2[index]);
        }
        
        return res;
    }
};