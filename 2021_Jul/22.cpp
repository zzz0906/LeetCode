class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> leftmaximum;
        vector<int> rightminimum;
        leftmaximum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            leftmaximum.push_back(max(nums[i],leftmaximum.back()));
        rightminimum.push_back(nums.back());
        for (int j = nums.size() - 2; j >= 0; j--)
            rightminimum.push_back(min(nums[j],rightminimum.back()));
        reverse(rightminimum.begin(),rightminimum.end());
        for (int i = 0; i < nums.size() - 1; i++){
            if (leftmaximum[i] <= rightminimum[i + 1])
                return i + 1;
        }
        return nums.size();
    }
};