class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.length() == 0) return "";
        unordered_map<char, int> count_c;
        unordered_map<char, bool> visited;
        for (int i = 0; i < s.length(); i++){
            visited[s[i]] = false;
            if (count_c.count(s[i]))
                count_c[s[i]]++;
            else
                count_c[s[i]] = 1;
        }
        //cout<<("a" < "c")<<endl;
        string ans = ""; ans += s[0]; visited[s[0]] = true; count_c[s[0]] --;
        for (int i = 1; i < s.length(); i++){
            if (visited[s[i]] == false) {
                while (s[i] < ans[ans.length()-1] && count_c[ans[ans.length()-1]] > 0 && ans != ""){
                    visited[ans[ans.length()-1]] = false;
                    ans = ans.substr(0,ans.length()-1);
                }
                ans = ans + s[i];
                visited[s[i]] = true; 
            }
            count_c[s[i]] --;
        }
        return ans;
        // last = s.length();
        // int last = 0;
        //assume a in 4 then b in 2 and 7 let it bigger than 4 we choose 7
        // string ans;
        // for (char i = 'a'; i <= 'z'; i++){
        //     int current = -1;
        //     for (int j = 0; j < s.length(); j++)
        //         if (s[j] == i){
        //             current = j;
        //         }
        //     if (current != -1){
        //         if (current > last){
        //             ans += i;

        //         }
        //     }
        // }
    }
};