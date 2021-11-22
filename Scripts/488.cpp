# include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int res, handSize;
    string check(string s){
        int start = 0;
        string res = "";
        while (start < s.size()){
            int end = start;
            while (end < s.size() - 1 && s[end + 1] == s[end]){
                end ++;
            }
            // reach the last element
            if (s[end + 1] == s[end]){
                end ++;
            }
            if (end - start + 1 < 3){
                for (int k = start; k <= end; k++){
                    res += s[k];
                }
            }
            start = end;
            start ++;
        }
        return res;
    }
    string wholeCheck(string s){
        string cur = check(s);
        while (cur != s){
            s = cur;
            cur = check(s);
        }
        return cur;
    }
    int min(int x, int y){
        return x < y ? x:y;
    }
    void dfs(string curS, string curh){
        curS = wholeCheck(curS);
        if (curS == ""){
            cout << curh << endl;
            res = min(res, handSize - curh.size());
            return;
        }
        if (curh.size() == 0)
            return;
        for (int i = 0; i < curS.size(); i++){
            for (int j = 0; j < curh.size(); j++){
                //cout << curS.substr(0, i) + curh[j] + curS.substr(i, curS.size() - i) << endl;
                string tmpcurh = curh;
                tmpcurh.erase(j);
                dfs(curS.substr(0, i) + curh[j] + curS.substr(i, curS.size() - i), tmpcurh); 
            }
        }
    }
    int findMinStep(string board, string hand) {
        handSize = hand.size();
        res = INT_MAX;
        dfs(board, hand);
        if (res == INT_MAX){
            return -1;
        }
        return res;
    }
};
int main(){
    Solution s;
    cout << s.findMinStep("WWRRBBWW","WRBRW") << endl;
}