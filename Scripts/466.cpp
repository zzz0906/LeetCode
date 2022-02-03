class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // str1 = s1*n1
        // s2*n*m can be obtained from str1, which means, we can delete some char in s1*n1 to be s2*n*m
        vector<int> repeatCnt(n1 + 1, 0);
        vector<int> nextIdx(n1 + 1, 0);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == s2.size()) {  
                        j = 0;
                        ++cnt;
                    }
                }
            }
            repeatCnt[k] = cnt;
            nextIdx[k] = j;
            for (int start = 0; start < k; ++start) {
                if (nextIdx[start] == j) { //duplicates one
                    int interval = k - start;
                    int repeat = (n1 - start) / interval;
                    // after start we will have the duplicates includes start - k
                    int patternCnt = (repeatCnt[k] - repeatCnt[start]) * repeat; // because cnt is a accumulated value, we need to use diff to find the duplicates in a pattern

                    // because we will have some duplicates in the tail of the end, we just move these part to the start
                    int remainCnt = repeatCnt[start + (n1 - start) % interval];
                    return (patternCnt + remainCnt) / n2;
                }
            }
        }
        return repeatCnt[n1] / n2;
    }
};