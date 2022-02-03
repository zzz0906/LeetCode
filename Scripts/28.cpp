#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int strStr(string haystack, string needle) {
    	bool find = true;
    	if (needle == "") return 0;
  		for (int i = 0;i<haystack.size();i++){
  			if (haystack[i] == needle[0]) {
  				int now1 = i;int now2 = 0;bool ffind = true;
  				while(now1 < haystack.size() && now2 < needle.size()){
  					if (haystack[now1] != needle[now2])
  						ffind = false;
  					if (ffind == false) break;
  					now1++;now2++;
				}
				if (now2 != needle.size()) ffind = false;
				if (ffind == true) return i;
			}
		}
		return -1;
    }
};
int main(){
	Solution::strStr("aaaaa","bba"); 
}
