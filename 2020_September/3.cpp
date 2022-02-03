#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 2; i <= s.length(); i++){
            if (s.length() % i != 0) continue;
            int fix_length = s.length() / i;
            int st = 0;
            string last = s.substr(st,fix_length);
            st = st + fix_length;
            bool flag = true;
            while (st < s.length()){
                string cur = s.substr(st,fix_length);
                cout<<cur<<endl;
                if (cur != last) {flag = false; break;}
                st = st + fix_length;
            }
            if (flag) return true;
        }
        return false;
    }
};
int main(){
    Solution s = Solution();
    cout<<s.repeatedSubstringPattern("aba")<<endl;
}