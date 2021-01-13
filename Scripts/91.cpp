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