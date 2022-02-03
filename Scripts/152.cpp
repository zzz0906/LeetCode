class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        vector<int> f1(nums.size());
        vector<int> f2(nums.size());
        f1[0] = nums[0];
        f2[0] = nums[0];
        for (int i = 1; i < nums.size();i++){
            f1[i] = max(max(f1[i-1]*nums[i],nums[i]),f2[i-1]*nums[i]);
            f2[i] = min(min(f1[i-1]*nums[i],nums[i]),f2[i-1]*nums[i]);
            res = max(res,f1[i]);
        }
        return res;
    }
};