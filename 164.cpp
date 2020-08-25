class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int mx = INT_MIN; int mn = INT_MAX;
        for (int i = 0; i < nums.size();i++){
                mx = max(mx,nums[i]);
                mn = min(mn,nums[i]);
        }
        int capacity = (mx-mn)/nums.size() + 1; int size = (mx-mn)/capacity + 1;
        vector<int> buckets_min(size, INT_MAX);
        vector<int> buckets_max(size,INT_MIN);
        for (int i=0; i<nums.size();i++){
            int index = (nums[i]-mn) / capacity;
            buckets_min[index] = min(nums[i],buckets_min[index]);
            buckets_max[index] = max(nums[i],buckets_max[index]);
        }
        int pre = 0; int answer = 0;
        for (int i=0; i<size; i++){
            if (buckets_min[i] == INT_MAX || buckets_max[i] == INT_MIN) continue;
            answer = max(answer,buckets_min[i] - buckets_max[pre]);
            pre = i;
        }
        return answer;
    }
};