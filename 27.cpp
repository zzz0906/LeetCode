#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int all = nums.size();
  		for (vector<int>::iterator it = nums.begin(); it != nums.end();it++){
  			if (*it == val) {
			  it = nums.erase(it);
			  all--;
			}
		}
		return all;
    }
};
