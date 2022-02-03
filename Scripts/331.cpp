class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream in(preorder);
        vector<string> v;
        string t = "";
        int cnt = 0;
        while (getline(in, t, ',')) v.push_back(t);
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] == "#") {
                if (cnt == 0) return false;
                --cnt;
            } else ++cnt;
        }
        return cnt == 0 && v.back() == "#";
    }
};