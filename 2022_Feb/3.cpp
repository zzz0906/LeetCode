
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<int> sum1;
        // i*nums1.size() + j
        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums2.size(); j++)   
                sum1.push_back(nums1[i] + nums2[j]);
        unordered_map<int,int> m;
        for (int i = 0; i < nums3.size(); i++)
            for (int j = 0; j < nums4.size(); j++)   
                if (m.count(nums3[i] + nums4[j]))
                    m[nums3[i] + nums4[j]] += 1;
                else
                    m[nums3[i] + nums4[j]] = 1;
        
        int res = 0;
        for (int i = 0; i < sum1.size(); i++){
            if (m.count(-1*(sum1[i])))
                res += m[-1*(sum1[i])];
        }
        return res;
    }
};