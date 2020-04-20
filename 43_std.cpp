#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.size(),l2=num2.size();
        string res(l1+l2,'0');
        if(l1==0||l2==0)
            return "";
        for(int i=l1-1;i>=0;i--){
            int add=0;
            for(int j=l2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=res[i+j+1]+add+mul%10-'0';
                res[i+j+1]='0'+sum%10;
                add=mul/10+sum/10;
            }
            res[i]+=add;
        }
        for(int i=0;i<l1+l2;i++)
            if(res[i]!='0')
                return res.substr(i);
        return "0";
    }
};