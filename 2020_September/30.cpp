class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; i < num.size(); i++)      
            if (nums[i] < mini && nums[i] > 0) mini = nums[i];
        if (mini > 1) return 1;
        
        
    }
};