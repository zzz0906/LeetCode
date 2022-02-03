class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 1; i <= k; i++){
            int tmp = nums[i-1];
            nums[i-1] = nums[nums.size()-i];
            int cur = i - 1;
            while (cur < nums.size() - k){
                int tmp_tmp = nums[cur+k];
                nums[cur+k] = tmp;
                tmp = tmp_tmp;
                cur = cur + k;
            }
            nums[cur+k] = tmp;
        }      
    }
};