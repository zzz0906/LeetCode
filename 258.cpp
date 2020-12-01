class Solution {
public:
    int addDigits(int num) {
        while (to_string(num).length() > 1){
            int tmp = 0;
            for (char s : to_string(num)){
                tmp += s - '0';
            }
            num = tmp;
        }
        return num;
    }
};