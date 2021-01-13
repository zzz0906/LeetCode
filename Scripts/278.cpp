// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 0; int ed = n;
        while (st < ed - 1) {
            long long tmp = (long(st)+long(ed))/2;
            int tmptmp = (int) tmp;
            if (isBadVersion(tmptmp)) ed = tmptmp;
            else st = tmptmp;
        }
        if (isBadVersion(ed) && ed < st) return ed;
        if (isBadVersion(st) && st < ed) return st;
        return ed;
    }
};