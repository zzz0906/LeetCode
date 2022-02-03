class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A == B){
            unordered_set<char> records;
            for (char c : A){
                if (records.count(c))
                    return true;
                else
                    records.insert(c);
            }
            return false;
        }else{
            if (A.length() != B.length()) return false;
            vector<pair<char, char>> dif;
            for (int i = 0; i < A.length(); i++){
                if (A[i] != B[i]) dif.push_back(make_pair(A[i], B[i]));
                if (dif.size() > 2) return false;
            }
            return dif.size() == 2 && dif[0].first == dif[1].second && dif[0].second == dif[1].first;
        }
        //no way
        return true;
    }
};