class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        for (int i = 0; i < (1 << nums.size()); i++){ //1111 => + + + +
            // process current bitmask
            int sum = 0;
            for (int j = 0; j < nums.size(); j++){
                if ((i >> j) & 1){
                    sum += nums[j];
                }else{
                    sum -= nums[j];
                }
            }
            if (sum == target){
                res++;
            }
        }
        return res;
    }
};