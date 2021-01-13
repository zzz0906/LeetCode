class Solution {
public:
    int trailingZeroes(int n) {
        int answer = 0;
        while (n){
            answer += n/5;
            n /= 5;
        }    
        return answer;  
    }
};