#include<bits/stdc++.h>
using namespace std;
string row[1000];
class Solution {
public:
    static string convert(string s, int numRows) {
    	for (int i = 0;i<numRows;i++) row[i] = "";
    	int now = 0;
    	int all = 0;
    	if (numRows == 1) return s;
  		while (all < s.size()){
  			if (now == 0){
  				for (int j = 0;j<numRows;j++){
  					if (all >= s.size()) break;
  					row[j]+=s[all];
  					all++;}
  				now = numRows - 2;
			}else
			{
				row[now]+=s[all];
				all++;
				now--;
			}
		}
		string answer = "";
		for (int i = 0;i<numRows;i++) answer += row[i]; 
		return answer;
    }
};
int main(){
	Solution::convert("abcde",3);
}
