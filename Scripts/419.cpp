#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void DFS_horizontal(int i, int j, vector<vector<bool> > & flag, vector<vector<char> >& board){
        //cout << i << endl;
        if (i < 0 || i >= board.size() || board[i][j] != 'X' || flag[i][j])
            return;
        flag[i][j] = true;
        DFS_horizontal(i-1,j,flag,board);
        DFS_horizontal(i+1,j,flag,board);
    }
    void DFS_vertical(int i, int j, vector<vector<bool> > & flag, vector<vector<char> >& board){
        //cout << i << j << endl;
        if (j < 0 || j >= board[0] .size() || board[i][j] != 'X' || flag[i][j])
            return;
        flag[i][j] = true;
        DFS_vertical(i,j+1,flag,board);
        DFS_vertical(i,j-1,flag,board);
    }

    int countBattleships(vector<vector<char> >& board) {
        vector<vector<bool> > flag(board.size(),vector<bool>(board[0].size(),false));
        int count = 0;
        for (int k = 0; k < board.size(); k++)
            for (int l = 0; l < board[k].size(); l++)
                if (!flag[k][l] && board[k][l] == 'X'){
                    //cout << k << l << endl;
                    count ++;
                    //cout<<count<<endl;
                    DFS_horizontal(k,l,flag,board);
                    flag[k][l] = false;
                    DFS_vertical(k,l,flag,board);
                }
        return count;
    }
};