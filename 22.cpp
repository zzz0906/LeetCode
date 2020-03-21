#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
    void generate(int left, int right, string str, vector<string>& res){
        if(left==0&&right==0){
            res.push_back(str);
            return;
        }
        if(left>0){
            generate(left-1, right, str+'(',res);
        }
        if(right>left&&right>0){
            generate(left,right-1,str+')',res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,n,"",res);
        return res;
    }
};
int main()
{
    Solution temple;
    vector<string> res1;
    res1 = temple.generateParenthesis(3);
    for(int i=0;i<res1.size();i++){
        cout<<res1[i]<<endl;
    }
  return 0;
}
 

