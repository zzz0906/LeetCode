#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<char> > tmpboard;
    bool endflag;
    vector<vector<char> > answerboard;
    bool isValidSudoku(vector<vector<char> > & board) {
        for (int i = 0; i < board.size();i++){
            bool flag[15];
            for (int j = 0; j <10;j++)
                flag[j] = false;
            for (int j = 0; j < board[i].size();j++){
                if (board[i][j] != '.'){
                    int num = int(board[i][j] - '0');
                    if (flag[num] == true){
                        return false;}
                    else
                    {
                        flag[num] = true;    
                    }
                }
            }
        }
        for (int i = 0; i <board[0].size();i++){
            bool flag[15];
            for (int j = 0; j <10;j++)
                flag[j] = false;
            for (int j = 0; j <board.size();j++){
                if (board[j][i] != '.'){
                    int num = int(board[j][i] - '0');
                    if (flag[num] == true){
                        return false;}
                    else
                    {
                        flag[num] = true;    
                    }
                }
            }
        }
        int i = 0;
        while (i < board.size()){
            int j = 0;
            while (j < board[0].size()){
                bool flag[15];
                for (int j = 0; j <10;j++)
                    flag[j] = false;
                for (int k = i; k < i + 3; k++)
                    for (int l = j; l < j + 3; l++)
                        if (board[k][l] != '.'){
                        int num = int(board[k][l] - '0');
                        if (flag[num] == true){
                            return false;}
                        else
                        {
                            flag[num] = true;    
                        }
                    }
                j = j + 3;
            }
            i = i + 3;
        }
        return true;
    }
    void dfs(int x, int y){
        if (x == tmpboard.size()-1 && y == tmpboard[0].size()-1){
            if (tmpboard[x][y] != '.'){
                endflag = true;
                answerboard = tmpboard;
                return;
            }
            for (int i = 1; i < 10;i++){
                tmpboard[x][y] = char(i+'0');
                if (isValidSudoku(tmpboard)){
                    endflag = true;
                    answerboard = tmpboard;
                    return; 
                }   
            }
            tmpboard[x][y] = '.';
            return;
        }
        if (tmpboard[x][y] == '.'){
            for (int i = 1; i < 10;i++){ 
                tmpboard[x][y] = char(i+'0');
                if (isValidSudoku(tmpboard)){
                    if (y+1 < tmpboard[0].size())
                        dfs(x,y+1);
                    else dfs(x+1,0);
                    if (endflag) return;
                }
                tmpboard[x][y] = '.';
            }
        }else{
            if (y+1 < tmpboard[0].size())
                dfs(x,y+1);
            else dfs(x+1,0);
            if (endflag) return;
        }
    }
    void solveSudoku(vector<vector<char> >& board) {      
            tmpboard = board;
            endflag = false;
            dfs(0,0);
            board = answerboard;
            return;
    }
};