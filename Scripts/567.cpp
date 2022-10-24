class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2){
            return false;
        }
        vector<int> m1(128), m2(128);
        for (int i = 0; i < n1; ++i) {
            ++m1[s1[i]]; ++m2[s2[i]];
        }
        if (m1 == m2) return true;
        for (int i = n1; i < n2; ++i) {
            ++m2[s2[i]];
            --m2[s2[i - n1]];
            if (m1 == m2) return true;
        }
        return false;
    }
};