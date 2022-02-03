class Solution {
public:
    bool reorderedPowerOf2(int N) {
        // 2 4 8 16 32 64 128 256 512 1024
        vector<vector<int>> map_2;
        for (int i = 0; i < 31; i++){
            int cur = pow(2,i);
            vector<int> tmp;
            for (int j = 0; j < 10; j++)
                tmp.push_back(0);
            int remain;
            while (cur > 0){
                remain = cur % 10;
                cur /= 10;
                tmp[remain] += 1;
            }
            map_2.push_back(tmp);
        }
        
        
        
        vector<int> ori;
        for (int i = 0; i < 10; i++) 
            ori.push_back(0);
        int rem;
        while (N > 0){
            rem = N % 10;
            N /= 10;
            ori[rem] ++;
        }
        
        for (int i = 0; i < 31; i++){
            vector<int> compt = map_2[i];
            bool eq = true;
            for (int j = 0; j < 10; j++)
                if (ori[j] != compt[j]){
                    eq = false;
                    break;
                }
            if (eq) return true;
        }
        
        return false;
    }
};