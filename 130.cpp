class Solution {
public:
    vector<vector<char>> tmp_board;
    vector<vector<bool>> flag;
    bool check(int i, int j) {
        if (flag[i][j] == false) return true;
        flag[i][j] = false;
        if (tmp_board[i][j] == 'X') return true;
        if (i == 0 || j == 0 || i >= tmp_board.size()-1 || j >= tmp_board[0].size()-1) return false;
        return check(i-1,j) && check(i+1,j) && check(i,j-1) && check(i,j+1);
    }
    void modify(int i, int j){
        if (flag[i][j] == false) return;
        flag[i][j] = false;
        if (tmp_board[i][j] == 'X') return;
        if (tmp_board[i][j] == 'O') tmp_board[i][j] = 'X';
        modify(i-1,j);
        modify(i+1,j);
        modify(i,j-1);
        modify(i,j+1);
    }
    void solve(vector<vector<char>>& board) {
        tmp_board = board;
        int k;
        for (int i = 0; i < board.size(); i++){
            vector<bool> tmp;
            for (int j = 0; j < board[i].size(); j++)
                tmp.push_back(true);
            flag.push_back(tmp);
        }
        vector<vector<bool>> tmp;
        tmp = flag;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++){
                flag = tmp;
                if (board[i][j] == 'O' && check(i, j)){
                    flag = tmp;
                    modify(i,j);
                }
            }
        board = tmp_board;
    }
};