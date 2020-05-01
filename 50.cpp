class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1/x;
        if (n > 0){
            double res = myPow(x,n/2);
            if (n % 2 == 0)
                return res*res;      
            else
                return res*res*x;
        }
        else{
           double res = myPow(x,n/2);
            if (n % 2 == 0)
                return res*res;      
            else
                return res*res*1/x; 
        }
    }
};