class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); ++i) {
            string s1 = num.substr(0, i);
            if (s1.size() > 1 && s1[0] == '0') break;
            for (int j = i + 1; j < num.size(); ++j) {
                string s2 = num.substr(i, j - i);
                long d1 = stol(s1), d2 = stol(s2);
                if ((s2.size() > 1 && s2[0] == '0')) break;
                long next = d1 + d2;
                string nextStr = to_string(next);
                if (nextStr != num.substr(j, nextStr.length())) continue;
                string allStr = s1 + s2 + nextStr;
                while (allStr.size() < num.size()) {
                    d1 = d2;
                    d2 = next;
                    next = d1 + d2;
                    nextStr = to_string(next);
                    allStr += nextStr;
                }
                // determine whether the fib string is equal to the original string 
                if (allStr == num) return true;

            }
        }
        return false;
    }
};