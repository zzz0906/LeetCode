class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> NOW = digits;
        int tmp = 1;
        for (int i = NOW.size()-1; i >=0; i--){
            NOW[i] += tmp;
            if (NOW[i] >= 10 && i == 0){
                tmp = NOW[i]/10;
                NOW[i] = NOW[i] % 10;
                NOW.insert(NOW.begin(),tmp);
                break;
            }
            if (NOW[i] >= 10){
                tmp = NOW[i]/10;       
                NOW[i] = NOW[i] % 10;
            }else{
                break;
            }
        }
        return NOW;
    }
};