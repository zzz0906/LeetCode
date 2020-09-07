#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
    void split(const string& s, vector<string>& tokens, char delim = ' ') {
        tokens.clear();
        auto string_find_first_not = [s, delim](size_t pos = 0) -> size_t {
            for (size_t i = pos; i < s.size(); i++) {
                if (s[i] != delim) return i;
            }
            return string::npos;
        };   
        size_t lastPos = string_find_first_not(0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != string::npos) {
            tokens.emplace_back(s.substr(lastPos, pos - lastPos));
            lastPos = string_find_first_not(pos);
            pos = s.find(delim, lastPos);
        }
    }
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> di;
        vector<string> vec;
        split(str, vec,' ');
        if (vec.size() != pattern.length()) return false;
        int i = 0;
        for (string each : vec){
            if (di.count(pattern[i]) == 0) di[pattern[i]] = each;
            else if (di[pattern[i]] != each) return false;
            i = i + 1;
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.wordPattern("abba","dog dog dog dog");
}