class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> v = nums, bit(n + 1);
        sort(v.begin(), v.end());
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) m[v[i]] = i + 1;
        for (int i = n - 1; i >= 0; --i) {
            res += getSum(lower_bound(v.begin(), v.end(), nums[i] / 2.0) - v.begin(), bit);
            update(m[nums[i]], bit);
        }
        return res;
    }
    int getSum(int i, vector<int>& bit) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    void update(int i, vector<int>& bit) {
        while (i < bit.size()) {
            bit[i] += 1;
            i += (i & -i);
        }
    }
};