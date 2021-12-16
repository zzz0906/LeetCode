class Solution {
    int INF = 1e9;
    int N;
    int minDist(int a, int b) {
        int dist = abs(a-b);
        return min(dist, N-dist);
    }
public:
    int findRotateSteps(string ring, string key) {
        N = ring.size();
        vector<int> prev(N, INF);
        vector<int> curr(N, INF);
        for(int i = 0; i < N; i++) {
            if(key[0] == ring[i]) prev[i] = minDist(0,i) + 1;
            else prev[i] = INF;
        } 
        for(int i = 1; i < key.size(); i++) {
            for(int j = 0; j < N; j++) {
                curr[j] = INF;
                if(key[i] == ring[j]) {
                   for(int k = 0; k < N; k++) {
                       if(prev[k] != INF) curr[j] = min(curr[j], prev[k] + minDist(j,k) + 1);
                   } 
                }
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};