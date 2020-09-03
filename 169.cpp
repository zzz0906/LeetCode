class Solution {
public:
    unordered_map<int, int> count_int;
    int majorityElement(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size();i++) {
            if (count_int.count(nums[i]) == 0){
                count_int[nums[i]] = 1;
            }else count_int[nums[i]] ++;
            res = max(count_int[nums[i]],res);
        }
        return res;
    }
};