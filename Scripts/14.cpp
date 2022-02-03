#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0) return "";
    	string answer = strs[0];
     	for (int i = 1;i<strs.size();i++){
     		int samen = 0;
     		for (int j = 0;j<min(strs[i].length(),answer.length());j++)
     			if (strs[i][j] == answer[j]) samen++; else break;
     		answer = strs[i].substr(0,samen);
		}
		return answer;
    }
};
int main(){
	vector<string> strs;
	string mid = "aab";
	strs.push_back(mid);
	mid = "c";
	strs.push_back(mid);
	cout<<Solution::longestCommonPrefix(strs);
	
}
