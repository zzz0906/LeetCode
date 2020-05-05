#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        int minl = newInterval[0];
        int maxr = newInterval[1];
        vector<vector<int> > answer;
        for (int i = 0; i < intervals.size();i++){
            if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]){
                maxr = max(maxr, intervals[i][1]);
                minl = min(minl, intervals[i][0]);}
            else if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[1]){
                maxr = max(maxr, intervals[i][1]);
                minl = min(minl, intervals[i][0]);}
            else if (intervals[i][0] >= newInterval[0] && intervals[i][1] <= newInterval[1]){
                continue;
            }
            else {
                answer.push_back(intervals[i]);
            }
        }
        vector<int> tmp;
        tmp.push_back(minl);
        tmp.push_back(maxr);
        bool inflag = false;
        for (int j = 0; j < answer.size(); j++)
            if (answer[j][0] > tmp[0]){
                inflag = true;
                answer.insert(answer.begin()+j,tmp);
                break;
            }
        if (inflag == false)
            answer.push_back(tmp);
        return answer;
    }
};