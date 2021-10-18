class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for (auto num : nums){
            mini = min(mini, num);
        }
        int res = 0;
        for (auto num : nums){
            res += num - mini;
        }
        return res;
    }
};