class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int start = 0;
        int end = -1;
        int ans = 0;
        for (int i = 0; i < timeSeries.size(); i++){
            if (timeSeries[i] > end) {ans += end - start + 1; start = timeSeries[i]; end = timeSeries[i] + duration - 1;}
            else{end = max(end, timeSeries[i] + duration - 1);}
        }
        ans += end - start + 1;
        return ans;
    }   
};