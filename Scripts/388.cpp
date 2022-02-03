class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0, n = input.length(), level = 0;
        unordered_map<int,int> m{{0,0}};
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (i < n && input[i] != '\n' && input[i] != '\t') ++i; // find the directory or file name
            if (i == n || input[i] == '\n') {
                string t = input.substr(start, i - start);
                if (t.find('.') != string::npos) {
                    //file
                    res = max(res, m[level] + (int)t.size());
                } else {
                    //directory
                    ++level;
                    m[level] = m[level - 1] + (int)t.size() + 1;
                }
                level = 0; 
            }else
                level++;
        }
        return res;
    }
};