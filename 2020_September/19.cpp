#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_d = 0;
        int tmp = low;
        if (tmp == 0) low_d = 1;
        else{
            while (tmp != 0){
                tmp = tmp/10;
                low_d ++;
            }
        }
        int high_d = 0;
        tmp = high;
        if (tmp == 0) high_d = 1;
        else{
            while (tmp != 0){
                tmp = tmp/10;
                high_d ++;
            }
        }
        vector<int> cur;
        vector<int> res;
        for (int i = 1; i < 10; i++) 
            cur.push_back(i);
        for (int i = low_d; i <= high_d; i++){
            int st = 0;
            while (st + i < 10){
                int mul = 1;
                int ans = 0;
                for (int j = st+i-1; j >= st; j--){
                    ans = ans + cur[j]*mul;
                    mul *= 10;
                }
                if (low <= ans && ans <= high) 
                    res.push_back(ans);
                st++;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    s.sequentialDigits(123,345);
}