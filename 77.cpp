#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int mxn;
    int mxk;
    unordered_map<int, int> count;
    vector<int> tmp;
    vector<vector <int> > answer;
    void dfs(int cur, int last){
        if (cur == mxk + 1){
            answer.push_back(tmp);
            return;
        }
        for (int i = last+1; i < mxn+1; i++){
            if (count[i] == 0){
                tmp.push_back(i);
                count[i] = 1;
                dfs(cur+1,i);
                tmp.pop_back();
                count[i] = 0;
            }            
        }
    }
    vector<vector<int> > combine(int n, int k) {
        mxn = n;
        mxk = k;
        dfs(1,0);
        return answer;
    }
};