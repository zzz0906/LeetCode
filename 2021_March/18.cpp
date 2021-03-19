class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int increasingP = 1;
        int decreasingP = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i - 1]) increasingP = decreasingP + 1;
            if (nums[i] < nums[i - 1]) decreasingP = increasingP + 1;
        }
        return max(increasingP,decreasingP);
    }
};