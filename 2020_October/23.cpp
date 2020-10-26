class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second = INT_MIN;
        stack<int> sta;
        for (int i = nums.size-1; i >= 0; --i) {
            if (nums[i] < second) return true;
            if (sta.size() != 0 && nums[i] > sta.top()){
                while (sta.size() != 0 && sta.top() < nums[i]){
                    second = sta.top();
                    sta.pop();
                }
            }
            sta.push(nums[i]);
        }
        return false;
    }
};