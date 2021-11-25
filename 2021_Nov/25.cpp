class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int res = nums[0];
        int sum = nums[0];
        while (right < nums.size()){
            res = max(res,sum);
            cout << left << endl;
            while (sum < 0 && left < right){
                sum -= nums[left];
                left ++;
            }
            while (left < right && nums[left] < 0){
                left ++;
            }
            sum += nums[right];
            right ++;
        }
        res = max(res,sum);
        return res;
    }
};