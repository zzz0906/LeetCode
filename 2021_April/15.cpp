class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int last = 0;
        int current = 1;
        int k = 1;
        while (k < n){
            k ++;
            int tmp = current;
            current = current + last;
            last = tmp;
        }
        return current;
    }
};