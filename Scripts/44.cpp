#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool ifm;
    string tmps,tmpp;
    void dfs(int index1,int index2) {
        if (index2 == tmpp.size() && index1 < tmps.size())
            return;
        if (index2 < tmpp.size() && index1 == tmps.size()){
            ifm = true;
            for (int i = index2; i<tmpp.size();i++)
                if (tmpp[i] != '*'){
                    ifm = false;
                    break;
                }
            return;
        }
        if (index2 == tmpp.size() && index1 == tmps.size()){
            ifm = true;
            return;
        }
        if (tmpp[index2] != '*'){
            if (tmpp[index2] == '?')
                dfs(index1+1,index2+1);
            if (ifm)
                return;
            if (tmpp[index2] != tmps[index1])
                return;
            else
                dfs(index1+1,index2+1);
        }else{
        for (int i = index1; i <= tmps.size();i++){
            dfs(i,index2+1);
            if (ifm)
                return;
        }}
    }
    bool isMatch(string s, string p) {
        if ((s.size() == 0) && (p == "*"))
            return true;
        ifm = false; 
        tmps = s;
        tmpp = p;
        dfs(0,0);
        return ifm;
    }
};