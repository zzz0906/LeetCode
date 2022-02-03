class Solution {
public:
    // disjoint set
    unordered_map<string, string> m;

    string find(string mail){
        return m[mail] == mail ? mail : find(m[mail]);
    }
    // map mail to name
    unordered_map<string, string> m2n;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto account : accounts){
            //store map from account to name
            for (int i = 1; i < account.size(); i++){
                m2n[account[i]] = account[0];
            }
            //build a map in the disjoint set
            for (int i = 1; i < account.size(); i++)
                if (!m.count(account[i])){
                    m[account[i]] = account[i];
                }
            
            //build the disjoint relationship for this elements 2..size -> 1
            for (int i = 2; i < account.size(); i++){
                m[find(account[i])] = find(account[1]);
            }
        }
        // reduce mails to the same root mails
        unordered_map<string, unordered_set<string>> m2ms;
        for (auto account : accounts){
            for (int i = 1; i < account.size(); i++){
                //use set to delete duplicates
                m2ms[find(account[i])].insert(account[i]);
            }
        }

        vector<vector<string>> res;
        for (auto kv: m2ms){
            vector<string> tmp;
            // name
            // m2n root mail -> name
            tmp.push_back(m2n[kv.first]);

            // no duplicate mails
            for (auto s: kv.second)
                tmp.push_back(s);
            
            // sort them
            sort(tmp.begin() + 1, tmp.end());
            
            res.push_back(tmp);
        }
        return res;
    }
};