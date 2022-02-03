class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maximum = 1;
        int i = 0;
        int res = 0;
        if (nums.empty())
            res = 1;
        else{
            if (nums[0] != 1){
                res = 1;
            }else{
                i = 1;
            }
        }
        while (maximum < n){
            //next one is maximum+1
            if (i < nums.size() && maximum + 1 >= nums[i]){
                maximum = nums[i] + maximum;
                i++;
            }else{
                maximum = maximum*2 + 1;
                res += 1;
            }
        }
        return res;
    }
};