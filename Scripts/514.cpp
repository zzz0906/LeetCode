# include <bits/stdc++.h>
using namespace std
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<vector<int>>> f(key.size(), vector<vector<int>>(ring.size, vector<int>(2,INT_MAX)));
        //init
        for (int j = 0; j < ring.size(); j++){
            if (key[0] = ring[j]){
                f[0][j][0] = 1 + j;//button + rotate
                f[0][j][1] = 1 + (j == 0 ? 0 : ring.size() - j); // button + anti rotate
            }
        }
        for (int i = 1; i < key.size(); i++)
            for (int j = 0; j < ring.size(); j++)
                if (f[i-1][j][0] != INT_MAX)
                    for (int k = 0; k < ring.size();k++)
                        if (key[i] == ring[k]){
                            f[i][k][0] = min(f[i][k][0], 1 + f[i-1][j][0] + abs(j - k))
                        }
    }
};