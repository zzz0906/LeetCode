#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        bool if_there_is_st = false, if_there_is_dot = false;
        for (int i = 0; i <s.length();i++){
            if (s[i] == '*'){
                if_there_is_st = true;
                break;
            }
            if (s[i] == '.'){ 
                if_there_is_dot = true;
                break;
            }
        }
        if (!(if_there_is_dot || if_there_is_st)){
            if (s != p)
                return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isMatch("aa","a")<<endl;
}