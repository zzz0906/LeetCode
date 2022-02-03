class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second = INT_MIN;
        stack<int> sta;
        // 1 -5 -2 -3
        // stack: 1
        // stack 1 -5 -2 -1 -3
        for (int i = nums.size()-1; i >= 0; --i) { // its's a reverse order
            if (nums[i] < second) return true;
            if (sta.size() != 0 && nums[i] > sta.top()){
                while (sta.size() != 0 && nums[i] > sta.top()){
                    second = sta.top();
                    // only we pop once
                    // we record the last value, and for the 132, this value is the `1`
                    sta.pop();
                }
            }
            sta.push(nums[i]);
        }
        return false;
    }
};