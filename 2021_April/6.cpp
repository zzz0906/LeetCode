class Solution {
public:
    int minOperations(int n) {
        int end = (n % 2 != 0)?n/2*2+1:n;
        int ans = 0;
        for (int i = (n-1)*2+1; i > end; i-=2){
            ans += i - end;
        }
        return ans;
    }
};