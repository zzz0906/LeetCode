#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        bool if_there_is_st = false, if_there_is_dot = false;
        for (int i = 0; i <p.length();i++){
            if (p[i] == '*'){
                if_there_is_st = true;
                break;
            }
            if (p[i] == '.'){ 
                if_there_is_dot = true;
                break;
            }
        }
        if (!(if_there_is_dot || if_there_is_st)){
            if (s != p)
                return false;
        }
        char precd;
        int pointtos = 0;
        for (int i = 0;i<p.length();i++){
            if (p[i] == '*'){
                if (precd == '.') {
                    precd = s[pointtos];
                }
                while (pointtos < s.length() && s[pointtos] == precd)
                    pointtos++;
                continue;
            }
            if (p[i] != '*' && p[i] != '.'){
                if (i + 1 < p.length() && p[i + 1] == '*'){
                    precd = p[i];
                    continue;}
                if (p[i] == s[pointtos])
                    pointtos++;
                else
                    return false;
                continue;
            }
            precd = p[i];
            if (pointtos == s.length() && i < p.length() - 1){
                i = i + 1;
                while (i < p.length())
                    if (p[i] == '.' && p[i] != '&')
                        return false;
                return true;
            }
        }
        if (pointtos < s.length() && p[p.length() - 1] != '*')
            return false;
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isMatch("aab","c*a*b")<<endl;
}