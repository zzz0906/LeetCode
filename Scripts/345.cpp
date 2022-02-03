class Solution {
public:
    string reverseVowels(string s) {
        int st,ed;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                st = i;
                break;
            }
        for (int j = s.length() - 1; j >= 0; j--)
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'|| s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'){
                ed = j;
                break;
            }
        while (st < ed){
            char tmp = s[st];
            s[st] = s[ed];
            s[ed] = tmp;
            for (int i = st + 1; i < s.length(); i++)
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                    st = i;
                    break;
                }
            for (int j = ed - 1; j >= 0; j--)
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'|| s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'){
                    ed = j;
                    break;
                }
        }
        return s;
    }
};