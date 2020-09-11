class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        bool flag1[secret.length()+1];
        bool flag2[secret.length()+1];
        memset(flag1, 0, sizeof(flag1));
        memset(flag2, 0, sizeof(flag2));
        for (int i = 0; i < secret.length(); i++){
            if (secret[i] == guess[i]) {
                A++;
                flag1[i] = 1;
                flag2[i] = 1;
            }
        }
        for (int i = 0; i < secret.length(); i++)
            for (int j = 0; j < secret.length(); j++)
                if (secret[i] == guess[j] && flag1[i] == 0 && flag2[j] == 0){
                    B++;
                    flag1[i] = 1;
                    flag2[j] = 1;
                }
        return to_string(A) + "A" + to_string(B) + "B";   
    }
};