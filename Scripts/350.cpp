class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> count_1;
        for (auto num:nums1)
            if (!count_1.count(num))
                count_1[num] = 1;
            else
                count_1[num] += 1;
        vector<int> count_2;
        for (auto num:nums2)
            if (count_1[num] > 0){
                count_2.push_back(num);
                count_1[num] --;
            }
        return count_2;
    }
};