#include<bits/stdc++.h>
using namespace std;
int answer[10000];
class Solution {
public:
    static bool isPalindrome(int x) {
    	if (x<0) return false;
    	memset(answer,0,sizeof(answer));
    	int mid = x;
    	int w = 0;
    	int remainder;
        while (mid != 0){
        	remainder = mid % 10;
        	mid = mid / 10;
        	answer[w++] = remainder;
		}
        for (int i = 0;i<w/2;i++)
        	if (answer[i] != answer[w-1-i]) return false;
        return true;
    }
};
