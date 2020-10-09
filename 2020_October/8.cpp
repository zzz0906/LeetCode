class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::iterator low = lower_bound(nums.begin(), nums.end(),target);
        if (*low == target) return (low-nums.begin());
        else return -1;
    }
};