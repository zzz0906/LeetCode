# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> numbers;
        for (auto c : p){
            if (!numbers.count(c)){
                numbers[c] = 1;
            }else{
                numbers[c] += 1;
            }
        }
        unordered_map<char,int> 

        int start = 0, end = 0;
        vector<int> res;

        while (start < s.size() -  p.size() + 1){
            if (start == end && !numbers.count(s[start])){
                while (start < (s.size() - p.size() + 1) && !numbers.count(s[start]))
                    start ++;
                end = start;
            }
            
            if (start < s.size() -  p.size() + 1){
                // expand end
                while (end - start + 1 < p.size()){
                    end ++;
                    if (!numbers.count(s[end])){
                        start = ++end;
                        break;
                    }
                    if (numbers[s[end]] <= 0){
                        start ++;
                        break;
                    }
                    numbers[s[end]] --;
                }

                if (end - start + 1 == p.size()){
                    res.push_back(start);
                    numbers[s[start++]] += 1;
                }

                // shrink start
            }
            
        }

        return res;
    }
};