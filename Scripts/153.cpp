class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int index = -1;
        for (int i = 0; i < nums.size()-1;i++)
            if (nums[i] > nums[i+1]){index = i; break;}
        if (index == -1) return nums[0];
        else
            return nums[index+1];
    }
};