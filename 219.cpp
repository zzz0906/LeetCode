class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> places;
        for (int i = 0; i < nums.size(); i++){
            if (places.count(nums[i]) == 0)
                places[nums[i]] = i;
            else{
                if (i - places[nums[i]] <= k) return true;
                else places[nums[i]] = i;
            }
        }
        return false;
    }
};