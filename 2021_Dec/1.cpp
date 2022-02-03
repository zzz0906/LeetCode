class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        vector<int> dp = {nums[0], nums[1],max(nums[0] + nums[2], nums[2])};
        int res = max(dp[0],max(dp[1],dp[2]));
        for (int i = 3; i < nums.size(); ++i) {
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 3]+nums[i]));
            if (dp[i] > res) res = dp[i];
        }
        //2 4
        //1 3
        // ?: where is 1 4
        return res;
    }
};