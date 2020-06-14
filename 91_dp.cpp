class Solution {
public:
    int f[1000000];
    int numDecodings(string s) {
        memset(f, 0, sizeof(f));
        if (s == "")
            return 0;
        if (s[0] == '0')
            return 0;
        f[0] = 1;
        if (s[1] == '0'){
            if (s[0] == '2' || s[0] == '1')
                f[1] = 1;
            else
                return 0;
        }else{
            if (((s[0]-'0')*10+s[1]-'0') <= 26)
                f[1] = 2;
            else
                f[1] = 1;
        }
        for (int i = 2; i < s.length(); i++){
            if (s[i] == '0'){
                if (s[i-1] == '2' || s[i-1] == '1')
                    f[i] = f[i-2];
                else
                    return 0;
            }else{
                if (s[i-1] == '0')
                    f[i] = f[i-1];
                else if (((s[i-1]-'0')*10+s[i]-'0') <= 26)
                    f[i] = f[i-1] + f[i-2];
                else f[i] = f[i-1]; 
            }
        }
        return f[s.length()-1];
    }
};