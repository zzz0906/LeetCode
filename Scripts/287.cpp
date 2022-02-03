class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        int n = nums.size();
        return sum - (1+n)*n/2;
    }
};