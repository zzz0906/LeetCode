class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1;
        if (n < 3){
            if (n == 2){
                return third;
            }else if (n == 1){
                return second;
            }else{
                return first;
            }
        }
        for (int i = 3; i <= n; i++){
            int tmp = third;
            third = first + second + third;
            int tmp2 = second;
            second = tmp;
            first = tmp2;
        }
        return third;
    }
};