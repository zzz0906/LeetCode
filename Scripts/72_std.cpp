class Solution {
public:
    int minDistance(string word1, string word2) {
        int E[1000][1000];
        int n = word1.size();
        int m = word2.size();
        for(int i = 0; i <= n; i++){
            E[i][0] = i;
        }
        for(int j = 1; j <= m; j++){
            E[0][j] = j;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int cost =  word1[i-1] == word2[j-1]?0:1;
                E[i][j] = min(min(E[i-1][j]+1,E[i][j-1]+1), E[i-1][j-1]+cost);
            }
        }
        return E[n][m];
    }
    
};
