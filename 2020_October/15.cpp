class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        k = k % nums.size();
        while (count < k){
            int tmp = nums[nums.size()-1];
            nums.erase(nums.begin() + nums.size()-1);
            nums.insert(nums.begin(),tmp);
            count++;
        }
    }
};