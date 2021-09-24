class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int,int> start2index;
        vector<int> starts;
        int index = 0;
        for (auto interval : intervals) {
            starts.push_back(interval[0]);
            start2index[interval[0]] = index; 
            index++;
        }
        sort(starts.begin(), starts.end());
        vector<int> res;
        for (auto interval : intervals) {
            vector<int>::iterator low = lower_bound(starts.begin(), starts.end(), interval[1]);
            if (starts.back() < interval[1]){
                res.push_back(-1);
            }else{
                res.push_back(start2index[*low]);
            }
        }
        return res;
    }
};