class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s == t) return true;
       unordered_map<char, int> f1;
       for (char c : s){
           if (f1.count(c) > 0) f1[c]++;
           else f1[c] = 1;
       }
       for (char c : t){
           if (f1.count(c) > 0) f1[c]--;
           else return false;
       }
       for (auto & x : f1){
           if (x.second != 0) return false;
       }
       return true;
    }
};