class Solution {
public:
    string smallestGoodBase(string n) {
        long long nVal = stol(n);
        for (long long i = 2; i <= sqrt(nVal); i++){
            long long res = 1;
            long long st = 1;
            while (res < nVal){
                st *= i;
                res += st;
            }
            if (res == nVal)
                return to_string(i);
        }
        return to_string((nVal - 1));
    }
};