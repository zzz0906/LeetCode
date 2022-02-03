#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
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
};