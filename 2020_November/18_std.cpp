#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        int n = intervals.size();
        if (n ==0 )
            return {};
        vector<vector<int> > res;
        vector<int> starts, ends;
        for (int i = 0; i < n; ++i) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0, j = 0; i < n; ++i) {
            if (i == n - 1 || starts[i + 1] > ends[i]) {
                res.push_back({starts[j], ends[i]});
                j = i + 1;
            }
        } 
        return res;
    }
};