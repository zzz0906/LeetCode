class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // find the total sum
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        // f[i][j] means before i the number of combination we can get sum j
        vector<vector<int>> f(nums.size() + 1, vector<int>(2*total + 1, 0));
        
        // because we use second dimension to store the current sum we can get, but sum can be negative, thus, we move sum into range (total, 2*total)
        f[0][total + nums[0]] = 1;
        // total +/- nums[0] may be the same value, pls use +=
        f[0][total - nums[0]] += 1;
        
        for (int i = 1; i < nums.size(); i++)
                //enumerate the sum value
                for (int j = -total; j <= total; j++){
                    //scale the range of j
                    int scaleJ = j + total;
                    if (f[i - 1][scaleJ] > 0){
                        f[i][scaleJ + nums[i]] += f[i - 1][scaleJ];
                        f[i][scaleJ - nums[i]] += f[i - 1][scaleJ];
                    }
                }
        // be careful when target > total sum, use index will result in out of range
        return abs(target) > total ? 0 : f[nums.size() - 1][target + total];
    }
};