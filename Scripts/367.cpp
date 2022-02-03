class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 0; i < num; i++){
            if ((long long)i*i > (long long)num){
                return false;
            }
            if (i*i == num){
                return true;
            }
        }      
        return true;
    }
};