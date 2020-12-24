class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++){
                int live = 0;
                int die = 0;
                if (i - 1 >= 0){
                    if (board[i-1][j] == 0) die ++; else live ++;
                    if (j - 1 >= 0) {
                        if (board[i-1][j-1] == 0) die ++; else live ++;
                        if (board[i][j-1] == 0) die ++; else live ++;
                    }
                    if (j + 1 < board[i].size()){
                        if (board[i-1][j+1] == 0) die ++; else live ++;
                        if (board[i][j+1] == 0) die ++; else live ++;
                    }
                }
                if (i + 1 < board.size()){
                    if (board[i+1][j] == 0) die ++; else live ++;
                    if (j - 1 >= 0) {if (board[i+1][j-1] == 0) die ++; else live ++;}
                    if (j + 1 < board[i].size()) {if (board[i+1][j+1] == 0) die ++; else live ++;}
                }
                cout << live << ' ' << die << endl;
                if (board[i][j] == 1){
                    //Any live cell with fewer than two live neighbors dies, as if caused by under-population.
                    if (live < 2) board[i][j] = 0;
                    //Any live cell with two or three live neighbors lives on to the next generation.
                    if (live == 2 || live == 3) board[i][j] = 1;
                    //Any live cell with more than three live neighbors dies, as if by over-population..
                    if (live > 3) board[i][j] = 0;
                }
                else{
                    //Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if (live == 3) board[i][j] = 1;
                }
            }
    }
};