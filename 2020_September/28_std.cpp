class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (left <= i && prod >= k) prod /= nums[left++];
            res += i - left + 1;
        }
        return res;
    }
};