class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i = 3; i < nums.size(); i++){
            if (nums[i] > min2){
                return true;
            }
            if (nums[i] < min1)
                min1 = nums[i];
            if (nums[i] > min1 && nums[i] < min2)
                min2 = nums[i];
        }
        return false;
    }
};