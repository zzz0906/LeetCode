class Solution {
public:
    int findNthDigit(int n) {
        int pos = 9;
        int st = 9;
        int len = 1;
        while (st < n){
            pos *= 10; len++; st += pos*len;  
        }
        if (st == 9)
            return n;
        n -= st;
        int cur = pow(10,len) + n / len;
        n %= len;
        int res = cur % 10;
        while (n > 0){
            n --;
            cur /= 10;
            res = cur % 10;
        }
        return res;
    }
};