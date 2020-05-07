#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
    int num;
    int cur[100];
    bool flag[100];
    int stopk;
    int pc;
    bool stopflag;
    void dfs(int index){
        if (index == num){
            pc++;
            if (pc == stopk){
                stopflag = true;
                return;
            }
        }
        for (int i = 1; i <=num;i++){
            if (flag[i] == false){
                cur[index] = i;
                flag[i] = true;
                dfs(index+1);
                flag[i] = false;
                if (stopflag)
                    return;
            }
        }
    }
    string getPermutation(int n, int k) {
        stopflag = false;
        pc = 0;
        stopk = k;
        memset(flag, 0, sizeof(flag));
        num = n;
        string answer = "";
        for (int i = 0; i < k;i++){
            answer += char('0'+cur[i]);
        }
        return answer;
    }
};