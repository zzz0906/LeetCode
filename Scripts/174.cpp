class Solution {
public:
    vector<vector<int>> myP;
    int ans = INT_MAX;
    void dfs(int x, int y, int current_health, int minimize){
        int tmp_current_health = current_health + myP[x][y];
        int tmp_minimize = tmp_current_health > 0 ? 0:tmp_current_health;
        if (tmp_minimize > ans) return;
        if (x == myP.size()-1 && y == myP[0].size()-1) {
            tmp_minimize = max(abs(tmp_minimize)+1,minimize);
            if (tmp_minimize < ans) ans = tmp_minimize;
            return;
        }
        if (y + 1 < myP[0].size()){
            if (abs(tmp_minimize)+1 < minimize) dfs(x,y+1,tmp_current_health,minimize);
        else dfs(x,y+1,tmp_current_health,abs(tmp_minimize)+1);
        }
        if (x + 1 < myP.size()){
            if (abs(tmp_minimize) + 1 < minimize) dfs(x+1,y,tmp_current_health,minimize);
        else dfs(x+1,y,tmp_current_health,abs(tmp_minimize)+1);
        }
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        myP = dungeon;
        // if (dungeon.size() == 0) return 0;
        // for (int i = 1; i < myP.size(); i++)
        //     myP[i][0] = myP[i-1][0] + myP[i][0];
        // for (int i = 1; i < myP[0].size(); i++)
        //     myP[0][i] = myP[0][i-1] + myP[0][i];
        // for (int i = 1; i < myP.size(); i++)
        //     for (int j = 1; j < myP[i].size(); j++)
        //         myP[i][j] = max(myP[i][j-1],myP[i-1][j]);
        // int ans = myP[myP.size()-1][myP[0].size()-1];
        // if (ans > 0) return 1;
        // else return abs(ans)+1;
        dfs(0,0,0,0);
        return ans;
    }
};