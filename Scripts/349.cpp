class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> count_1;
        for (auto num:nums1)
            if (!count_1.count(num))
                count_1[num] = 1;
        set<int> count_2;
        for (auto num:nums2)
            if (count_1.count(num))
                count_2.insert(num);
        vector<int> ans;
        for (auto num: count_2)
            ans.push_back(num);
        return ans;
    }
};