#include<bits/stdc++.h>
using namespace std;
stack<char> bra;
char mid;
class Solution {
public:
    static bool isValid(string s) {
    	while(!bra.empty()) bra.pop();
		for (int i = 0;i<s.size();i++){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')	bra.push(s[i]);
			if (s[i] == ')') {
				if (bra.empty()) return false;
				mid = bra.top();
				bra.pop();
				if (mid != '(') return false;
			}
			if (s[i] == '}') {
				if (bra.empty()) return false;
				mid = bra.top();
				bra.pop();
				if (mid != '{') return false;
			}
			if (s[i] == ']') {
				if (bra.empty()) return false;
				mid = bra.top();
				bra.pop();
				if (mid != '[') return false;
			}
		}
		if (!bra.empty()) return false;
		return true;
    }
};
int main(){
	cout<<Solution::	isValid("()");
}
