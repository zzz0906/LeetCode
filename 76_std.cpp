#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            //-- represent the if it do not in the target it will be < 0
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) {--cnt;}
                //if won't >0 not in target because for each one we must have -- in line 12
                ++left;
            }
        }
        cout<<res<<endl;
        return res;
    }
};
int main(){
    Solution * s = new Solution();
    s->minWindow("fffabc","abc");
}
