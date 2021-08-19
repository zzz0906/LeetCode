class Solution {
public:
    int numDecodings(string s) {
        if (s == "") return 0;
        if (s == "0") return 0;
        if (s.length() == 1)
            return 1;
        if (s.length() == 2){
            if (((s[0]-'0')*10+s[1]-'0') <= 26 && s[0] != 0)
                return 2;
            else
                return 1;
        }

        // select the two digits in the behind

        //1. it's valid; the last one is zero, we cannot only select tmp[1]
        //2. it's valid the last one is not zero, we can still select tmp[1] and let tmp[0] belong to others
        //3. it's invalid, the last one is zero, we cannot deal with the zero, return 0
        //4. it's invalid, the last one is not zero, we can hope if we divid them in another can get a better result.
        string tmp = s.substr(s.length()-2,2);
        //numDecodings(s.substr(0,s.length()-2))*numDecodings()+
        if (((tmp[0]-'0')*10+tmp[1]-'0') <= 26 && tmp[0] != 0){
            if (tmp[1] == '0')
                return numDecodings(s.substr(0,s.length()-2));
            else
                return numDecodings(s.substr(0,s.length()-2))+numDecodings(s.substr(0,s.length()-1))*numDecodings(s.substr(s.length()-1,1));
        }
        else{
            if (tmp[1] == '0')
                return 0;
            else
                return numDecodings(s.substr(0,s.length()-1))*numDecodings(s.substr(s.length()-1,1));
        }
    }
};