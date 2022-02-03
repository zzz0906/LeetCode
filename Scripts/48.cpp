#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int left = 0;
        int right = matrix.size();
        while (left < right) {
            int tmp = left;
            while (tmp < right-1) {
                int times = 0;
                int i = left; int j = tmp;
                int tmpstore = matrix[i][j];
                while (times <= 3){
                    int midtmp = tmpstore;
                    tmpstore = matrix[j][matrix.size()-i-1];
                    matrix[j][matrix.size()-i-1] = midtmp;
                    midtmp = i;
                    i = j;
                    j = matrix.size()-midtmp-1;
                    times ++;
                }
                //left,tmp
                tmp++;
            }
        left++;
        right--;
        }
    }
};