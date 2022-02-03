class Solution {
public:
    bool a[5000005];
    int countPrimes(int n) {
        if (n == 0 || n == 1 || n == 2) return 0;
        memset(a, 0, sizeof(a));
        int current = 2;
        int ans = 0;
        while (current < n) {
            ans++;
            int i = 0;
            //sieve
            long long tmp = current;
            tmp = tmp * tmp;
            if (tmp < n){
                while (current*current+i*current < n){
                    a[current*current+i*current] = 1;
                    i++;
                }
            }
            //find next
            current = current + 1;
            while (a[current] != 0)
                current++;
        }
        return ans;
    }
};