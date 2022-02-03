class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, maxx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1){
                res ++;
            }else{
                res = 0;
            }
            if (res > maxx){
                maxx = res;
            }
        }
        return maxx;
    }
};