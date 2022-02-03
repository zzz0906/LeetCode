class Solution {
public:
    vector<int> leftbucket;
    vector<int> leftprefix;
    unordered_map<int,int> leftkey;

    vector<int> rightbucket;
    vector<int> rightprefix;
    unordered_map<int,int> rightkey;
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        for (int i = 0; i < nums.size();i++){
            if (leftkey.back() == nums[i]){
                leftbucket[leftbucket.size() - 1] += 1;
                leftprefix[leftprefix.size() - 1] += 1;
            }else{
                leftkey.push_back(nums[i]);
                leftbucket.push_back(1);
                leftprefix.push_back(leftprefix[leftprefix.size() - 1] + 1);
            }
        }
        index = 0;
        for (int i = nums.size() - 1; i >= 0; i--){
            if (rightkey.back() == nums[i]){
                rightbucket[rightbucket.size() - 1] += 1;
                rightprefix[rightprefix.size() - 1] += 1;
            }else{
                rightkey[nums[i]] = index;
                rightbucket.push_back(1);
                rightprefix.push_back(rightprefix[rightprefix.size() - 1] + 1);
                index ++;
            }
        }
        int res = 0;
        for (auto ele : nums){
            res += left
        }
    }
};