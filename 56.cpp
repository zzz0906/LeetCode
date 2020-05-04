#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        if (intervals.size() == 0)
            return {};
        vector<vector<int> > answer;
        int max = 0;
        for (int i = 0; i < intervals.size();i++)
          if (intervals[i][1] > max) max = intervals[i][1];
        int buckets[max+5];
        for (int i = 0; i < max+5;i++)
            buckets[i] = 0;
        for (int i = 0; i < intervals.size();i++)
            for (int j = intervals[i][0]; j <= intervals[i][1]; j++)
                buckets[j] = 1;
        int j = 0;
        while(buckets[j] == 0)
            j++;
        int start;
        start = -1;
        for (int i = j; i < max+5;i++){
            if (buckets[i] == 1 && start == -1)
                start = i;
            if (buckets[i] == 0 && start != -1){
                vector<int> tmp;
                tmp.push_back(start);
                tmp.push_back(i-1);
                answer.push_back(tmp);
                start = -1;
            }
        }
        return answer;
    }
};