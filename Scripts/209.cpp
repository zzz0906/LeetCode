class Solution {
public:
    int sum(vector<int> l){
        int ans = 0;
        for (int i = 0; i < l.size(); i++)
            ans += l[i];
        return ans;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (sum(nums) < s) return 0;
        int ans_len = INT_MAX;
        deque<int> ans;
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (current_sum < s){
                ans.push_back(nums[i]);
                current_sum += nums[i];
            }
            else{
                ans_len = (ans_len < ans.size())?ans_len:ans.size();
                ans.push_back(nums[i]);
                current_sum += nums[i];
                while (current_sum - ans.front() >= s){
                    current_sum -= ans.front();
                    ans.pop_front();
                }
            }
        }
        if (current_sum >= s){
            while (current_sum - ans.front() >= s){
                    current_sum -= ans.front();
                    ans.pop_front();
                }
            ans_len = (ans_len < ans.size())?ans_len:ans.size();
        }
        return ans_len;
    }
};