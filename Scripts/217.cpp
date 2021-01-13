class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> count_n;
        for (int i = 0; i < nums.size(); i++){
            if (count_n.count(nums[i]) == 0)
                count_n[nums[i]] = 1;
            else return true;
        }      
        return false;
    }
};