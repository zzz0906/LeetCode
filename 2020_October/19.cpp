class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        for (int i = 1; i <=6; i++){
            int current = 0;
            bool flag = true;
            for (int j = 0; j < A.size(); j++){
                if (A[j] != i && B[j] != i){
                    flag = false;
                    break;
                }
                if (A[j] != i)
                    current++;
            }
            if (flag && current < ans) ans = current;
        }
        for (int i = 1; i <=6; i++){
            int current = 0;
            bool flag = true;
            for (int j = 0; j < B.size(); j++){
                if (A[j] != i && B[j] != i){
                    flag = false;
                    break;
                }
                if (B[j] != i)
                    current++;
            }
            if (flag && current < ans) ans = current;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};                                