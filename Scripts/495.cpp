class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int start = timeSeries[0];
        int last = 0;
        int res = 0;
        for (int i = 1; i < timeSeries.size(); i++){
            if (timeSeries[i] > timeSeries[last] + duration - 1){
                res += timeSeries[last] + duration - 1 - start + 1;
                start = timeSeries[i];
            }
            last = i;
        }
        res += timeSeries[last] + duration - 1 - start + 1;
        return res;
    }
};