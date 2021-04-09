class Solution {
public:
    bool halvesAreAlike(string s) {
        int tmp = 0;
        int tmp2 = 0;
        if (s.size() % 2 != 0)
            return false;
        int co = 0;
        for (auto c: s){
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                tmp++;
            if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') && co < s.size() / 2)
                tmp2 ++;
            co ++;
        }
        //cout << tmp;
        //cout << tmp2;
        if (tmp % 2 == 0 && tmp2 == tmp / 2)
            return true;
        return false;
    }
};