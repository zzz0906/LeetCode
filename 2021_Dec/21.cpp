class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n != 1){
            // equal to n % 2 == 0
            if (n - 2*(n/2) != 0) return false;
            // divide 2
            n = n / 2;
        }
        return true;      
    }
};