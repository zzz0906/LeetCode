class Solution {
public:
    vector<string> table = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
    string toHex(int num) {
        string res = "";
        if (num == 0) return "0";
        if (num > 0){
            while (num > 15){
                int tmp = num % 16;
                num = num / 16;
                res = table[tmp] + res;
            }
            res = table[num] + res;
        }else{
            unsigned int tmp = pow(2,31);
            tmp = tmp - 1 + tmp;
            tmp = tmp  + num + 1;
            //cout << tmp << endl;
            while (tmp > 15){
                int tmp2 = tmp % 16;
                tmp = tmp / 16;
                res = table[tmp2] + res;
            }
            res = table[tmp] + res;
        }
        return res;
    }
};