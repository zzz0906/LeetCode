class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> prefix_sum(nums.size(),0);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            prefix_sum[i] = nums[i] + prefix_sum[i-1];
        }
        if (prefix_sum.back() % 2 != 0)
            return false;
        int req = prefix.back() / 2;
        // for (int i = 0; i < nums.size(); i++)
        //     for (int j = i; j < nums.size(); j++){
        //         if (i == j){
        //             if (nums[i] == prefix_sum.back() / 2){
        //                 return true;
        //             }
        //         }else{
        //             if (prefix_sum[j] - prefix_sum[i] == prefix_sum.back() / 2)
        //                 return true;
        //         }
        //     }
        // return false;
        vector<vector<bool> > dp(nums.size() + 5, vector<bool> (20005, false));
        for (int i = 0; i < nums.size(); i++){
            dp[i][nums[i]] = true;
        }
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < 20005; j++){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        return dp[i][req];
    }
};