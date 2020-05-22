class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = (int)nums.size() - 1;
        for (int i = 0; i <= blue; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[blue--]);
            } 
        }
    }
};