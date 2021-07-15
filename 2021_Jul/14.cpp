class Solution {
public:
    string customSortString(string order, string str) {
        int count[26];
        memset(count, 0, sizeof(count));
        string add = "";
        for (auto c : str) {
            if (order.find(c) < order.length()) 
                count[c - 'a'] += 1;
            else
                add += c;
        }
        string res;
        for (auto c : order){
            if (count[c - 'a'] != 0){
                for (int i = 0; i < count[c - 'a']; i++)
                    res += c;
            }
        }

        return res + add;
    }
};