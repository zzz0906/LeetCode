#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string intToRoman(int num) { 
        string resStr = "";
        vector<int> value{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> symbol{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<value.size();i++)
            while(num>=value[i])
            {
                resStr+=symbol[i];
                num-=value[i];
            }
        return resStr;
    }
};
