#include<bits/stdc++.h>
using namespace std;
string tostring(char c){
	stringstream stream;
	stream<<c;
	return stream.str();
}
class Solution {
public:
    static string longestPalindrome(string s) {
    	int answer = 0;
    	string answermid="";
    	string realanswer;
  		for (int i = 0;i<s.size();i++){
  			int now = 1;
  			int b = i;
  			int e = i;
  			answermid = tostring(s[i]); 
  			while (b-1>=0 && e+1<s.size() && s[b-1] == s[e+1]){
  				b = b-1;
				e = e+1;
				now++;now++;
				answermid = tostring(s[b])+answermid+tostring(s[e]);	
			}
			if (now>answer) {
			answer = now;
			realanswer = answermid;
			if (now == s.size()) return answermid;}
  			now = 1;
  			b = i;
  			e = i;
			if (b-1 >= 0 && s[b-1] == s[b]){
				answermid = tostring(s[b-1])+tostring(s[b]); 
				b = b -1;now++;
				while (b-1>=0 && e+1<s.size() && s[b-1] == s[e+1]){
  				b = b-1;
				e = e+1;
				now++;now++;	
				answermid  = tostring(s[b])+answermid+tostring(s[e]);
				}
			} 
			if (now > answer){
			answer = now;
			realanswer = answermid;}
			now = 1;
  			b = i;
  			e = i;
  			if (e+1<s.size() && s[e+1] == s[e]){
  				answermid = tostring(s[e+1])+tostring(s[e]);
  				e = e + 1;
				now++;	
				while (b-1>=0 && e+1<s.size() && s[b-1] == s[e+1]){
  				b = b-1;
				e = e+1;
				now++;now++;
				answermid  = tostring(s[b])+answermid+tostring(s[e]);
				}
			}
			if (now > answer) {
			answer = now;
			realanswer = answermid;}
		}
		return realanswer;    
    }
};
