class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty() || nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        int n = nums.size(), all = (1 << n) - 1, target = sum / 4;
        vector<int> masks, validHalf(1 << n, false);
        for (int i = 0; i <= all; ++i) {
            int curSum = 0;
            for (int j = 0; j <= 15; ++j) {
                if ((i >> j) & 1) curSum += nums[j];
            }
            if (curSum == target) {
                for (int mask : masks) {
                    if ((mask & i) != 0) continue;
                    int half = mask | i;
                    validHalf[half] = true;
                    if (validHalf[all ^ half]) return true;
                }
                masks.push_back(i);
            }
        }
        return false;
    }
};