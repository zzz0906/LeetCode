class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pi = 1;
        int zero = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0)
                pi *= nums[i];
            else
                zero++;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0 && zero == 1)
                ans.push_back(pi);
            if (nums[i] == 0 && zero > 1)
                ans.push_back(0);
            if (nums[i] != 0 && zero >= 1)
                ans.push_back(0);
            if (nums[i] != 0 && zero == 0)
                ans.push_back(pi/nums[i]);
        }
        return ans;
    }
};