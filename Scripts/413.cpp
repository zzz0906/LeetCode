class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        vector<int> diff;
        for (int i = 1; i < nums.size(); i++){
            diff.push_back(nums[i] - nums[i - 1]);
        }
        int res = 0;
        for (int i = 0; i < diff.size(); i++){ //enumerate for the start
            for (int j = i + 1; j < diff.size(); j++){
                if (diff[j] == diff[i]){
                    res += 1;
                }else
                    break;
            }
        }
        
        return res;
    }
};