class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<int> opt;
        vector<int> pro_opt;
        opt.push_back(nums[0]);
        pro_opt.push_back(nums[0]);
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (pro_opt[i-1]*nums[i] < k){
                pro_opt[i] = nums[i] * pro_opt[i-1];
                opt[i] = opt[i-1];
                ans += i-opt[i]+1;// opt[i]..i 2..i i-1..i i..i
            }else{
                pro_opt[i] = nums[i] * pro_opt[i-1];
                for (int j = opt[i] + 1; j <= i; j++){
                    pro_opt[i] = pro_opt[i]/nums[j];
                    if (pro_opt[i] < k){
                        opt[i] = j+1;
                        ans += i-opt[i] + 1;
                        break;
                    }
                }
                if (pro_opt[i] = 1){
                    pro_opt[i] = 1;
                    opt[i] = i+1;
                }
            }
        }
        return ans;      
    }
};