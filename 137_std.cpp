class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); ++i) {
            two |= one & nums[i];
            one ^= nums[i];
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};