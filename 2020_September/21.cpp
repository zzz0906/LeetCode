class Solution {
public:
    int dis_cap[10000];
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        memset(dis_cap, 0, sizeof(dis_cap));
        for (int i = 0; i < trips.size(); i++) {
            for (int j = trips[i][1]; j <= trips[i][2]-1; j++) {
                dis_cap[j] += trips[i][0];
                if (dis_cap[j] > capacity) return false;
            }
        }
        return true;
    }
};