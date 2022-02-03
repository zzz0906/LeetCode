#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> A_mirror;
    vector<int> res; 
    void dfs(vector<int> current, bool enume[4], int count_n){
        if (count_n == 4){
            if (current[0] > 2) return;
            if (current[0] == 2 && current[1] > 3) return;
            if (current[2] > 5) return;
            if (current[0] > res[0]){res = current;return;}
            if (current[0] == res[0] && current[1] > res[1]){res = current;return;}
            if (current[0] == res[0] && current[1] == res[1] && current[2] > res[2]){res = current; return;}
            if (current[0] == res[0] && current[1] == res[1] && current[2] == res[2] && current[3] > res[3]){res = current; return;}
            return;
        }
        for (int i = 0; i < 4; i++){
            if (count_n == 2 && A_mirror[i] > 5) continue;
            if (count_n == 0 && A_mirror[i] > 2) continue;
            if (enume[i] == true){
                vector<int> tmp = current;
                tmp.push_back(A_mirror[i]);
                enume[i] = false;
                dfs(tmp,enume,count_n+1);
                enume[i] = true;
            }
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        res.push_back(-1); res.push_back(-1);res.push_back(-1);res.push_back(-1);
        bool tmp[4] = {true,true,true,true};
        A_mirror = A;
        vector<int> empty;
        dfs(empty,tmp,0);
        string answer = "";
        if (res[0] == -1) return "";
        else {
            for (int i = 0; i < 4; i++){
                answer += to_string(res[i]);
                if (i ==1) answer += ":";
            }
        }
        return answer;
    }
};
int main(){
    Solution s = Solution();
    vector<int> A;
    A.push_back(2);
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    cout<<s.largestTimeFromDigits(A)<<endl;
}