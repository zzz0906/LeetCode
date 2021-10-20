class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int index = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= g[index]){
                index ++;
                res++;
            }
            if (index == g.size()){
                break;
            }
        }
        
        return res;
    }
};