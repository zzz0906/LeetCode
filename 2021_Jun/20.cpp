class Solution {
public:
    int res = INT_MAX;
    vector<vector<int> gridG;
    int dfs(int curx, int cury, int value,vector<vector<bool> > bennTo){
        if (curx == 0 && cury == 0){
            res = min(res,value);
            return;
        }
        int ans = max(gridG[curx][cury],value);
        if (curx - 1 >= 0 && bennTo[curx - 1][cury] == false){
            vector<vector<bool> > tmp = bennTo;
            tmp[curx - 1][cury] = true;
            dfs(curx - 1,cury,ans,tmp)
        }

        if (curx + 1 < gridG.size() && bennTo[curx + 1][cury] == false){
            vector<vector<bool> > tmp = bennTo;
            tmp[curx + 1][cury] = true;
            dfs(curx + 1,cury,ans,tmp)
        }

        if (cury - 1 >= 0 && bennTo[curx][cury - 1] == false){
            vector<vector<bool> > tmp = bennTo;
            tmp[curx][cury - 1] = true;
            dfs(curx,cury - 1,ans,tmp)
        }

        if (cury + 1 < gridG[0].size() && bennTo[curx][cury + 1] == false){
            vector<vector<bool> > tmp = bennTo;
            tmp[curx][cury + 1] = true;
            dfs(curx,cury + 1,ans,tmp)
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        gridG = grid;
        int stx = grid.size()-1; int sty = grid[0].size()-1;
        vector<vector<bool>> beginning(grid.size(),vector<int> (gridG[0].size(),false));
        dfs(stx, sty,INT_MIN,beginning);
        return res;
    }
};