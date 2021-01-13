class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> value;
        deque<int> index;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1){
                while (!value.empty() && value.back() < nums[i]) {value.pop_back();index.pop_back();}
                value.push_back(nums[i]);
                index.push_back(i);
            }else{
                while (!value.empty() && index.front() <  i - k + 1) {value.pop_front();index.pop_front();}
                while (!value.empty() && value.back() < nums[i]) {value.pop_back();index.pop_back();}
                value.push_back(nums[i]);
                index.push_back(i);
                res.push_back(value.front());
            }
        }
        return res;
    }
};