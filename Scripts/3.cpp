#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int lengthOfLongestSubstring(string s) {  
	  int n = s.length();  
	  int answer = 0;  
	  int exist[256];
	  int now = 0;
	  int min = 0;
	  memset(exist,0,sizeof(exist));  
	  for (int i =0;i<s.length();i++){
	  	if (exist[s[i]] == 0){
	  		exist[s[i]] = i+1;
	  		now++;
	  		if (now > answer) answer = now;
		}else{
			now = i-exist[s[i]]+1;
			int midd = exist[s[i]];
			for (int j = min;j<exist[s[i]];j++)
				exist[s[j]] = 0;
			min = midd;
			if (now > answer) answer = now;
			exist[s[i]] = i + 1;
		}
	  }
	  return answer;
	}	
};
