class Solution {
public:
    int maxPower(string s) {
        char last = ' ';
        int rc = 1;
        int ans = 1;
        for (char c: s){
            if (c != last){
                last = c;
                rc = 1;
            }else{
                rc++;
                if (rc > ans) ans = rc;
            }
        }
        return ans;
    }
};