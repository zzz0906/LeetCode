class Solution {
public:

    bool find132pattern(vector<int>& nums) {
        vector<pair<int, int>> numsIndex;
        for (int i = 0; i < nums.size(); i++)
            numsIndex.push_back(make_pair(nums[i],i));
        sort(numsIndex.begin(), numsIndex.end(), [](pair<int ,int> a, pair<int ,int> b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        int minindex = min(numsIndex[0].second, numsIndex[1].second);
        int maxindex = max(numsIndex[0].second, numsIndex[1].second);
        
        for (int i = 2; i < numsIndex.size(); i++){
            if (numsIndex[i].second > minindex && numsIndex[i].second < maxindex){
                return true;
            }
            minindex = min(minindex, numsIndex[i].second);
            maxindex = max(maxindex, numsIndex[i].second);
        }
        
        return false; 
    }
};