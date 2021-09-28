# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k --;

        while (k > 0){
            long long step = 0, first = cur, last = first + 1;
            while (last <= n){
                step += min(last,n) - first;
                first *= 10;
                last *= 10;
            }
            if (step <= k){
                cur ++;
                k -= step;
            }else{
                cur *= 10;
                k --;
            }
        }

        return cur;
    }
};