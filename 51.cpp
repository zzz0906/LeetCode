#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> find;
    vector<vector<string> > answer;
    int nu;
    void dfs(int now){
        if (now == nu+1){
            vector<string> answertmp = find;
            for (int i = 0; i < nu;i++)
                for (int j = 0; j < nu; j++)
                    if (answertmp[i][j] == 'X')
                        answertmp[i][j] = '.';
            for (int i = 0; i < answer.size(); i++){
                bool same = true;
                for (int j = 0; j < answer[i].size(); j++){
                    if (answer[i][j] != answertmp[j]){
                        same = false;
                        break;
                    }
                }
                if (same) return;
            }
            answer.push_back(answertmp);
            return;
        }
        int i = now-1;
        for (int j = 0; j < nu; j++)
            if (find[i][j] != 'X'){
                vector<string> tmpforfind = find;
                find[i][j] = 'Q';
                for (int k = 0; k < nu; k++){
                    if (k != j)
                        find[i][k] = 'X';
                    if (k != i)
                        find[k][j] = 'X';
                }
                int nowx = i; int nowy = j;
                while (nowx - 1 >= 0 && nowy - 1 >= 0){
                    find[nowx - 1][nowy - 1] = 'X';
                    nowx --; nowy --;
                }
                nowx = i; nowy = j;
                while (nowx + 1 < nu && nowy + 1 < nu){
                    find[nowx + 1][nowy + 1] = 'X';
                    nowx ++; nowy ++;
                }
                nowx = i; nowy = j;
                while (nowx + 1 < nu && nowy - 1 >= 0){
                    find[nowx + 1][nowy - 1] = 'X';
                    nowx ++; nowy --;
                }

                nowx = i; nowy = j;
                while (nowx - 1 >= 0 && nowy + 1 < nu){
                    find[nowx - 1][nowy + 1] = 'X';
                    nowx --; nowy ++;
                }
                dfs(now+1);
                find = tmpforfind;
            }
    }
    vector<vector<string> > solveNQueens(int n) {
        nu = n;
        vector<string> tmp;
        for (int i = 0; i < n;i++){
            string tmpstr = "";
            for (int j = 0; j < n; j++)
                tmpstr += ".";
            tmp.push_back(tmpstr);
        }
        find = tmp;
        dfs(1);
        return answer;
    }
};