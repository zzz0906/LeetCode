class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> value2index;
        for (int i = 0; i < nums2.size(); i++)
            value2index[nums2[i]] = i;
        vector<int> res;
        for (auto num : nums1){
            int nextIndex = -1;
            for (int i = value2index[num] + 1; i < nums2.size(); i++){
                if (nums2[i] > num){
                    nextIndex = i;
                    break;
                }
            }
            if (nextIndex != -1)
                res.push_back(nums2[nextIndex]);
            else
                res.push_back(-1);
        }
        return res;
    }
};