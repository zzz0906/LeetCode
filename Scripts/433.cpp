class Solution {
public:
    unordered_map<string,int> validGenes;
    int res;
    vector<char> changes{'A','C','G','T'};

    void dfs(string cur, string end, unordered_set<int> reach, int step){
        if (cur == end){
            if (res != -1){
                res = min(res,step);
            }
            else{
                res = step;
            }
            return;
        }
        for (int i = 0; i < cur.length(); i++){
            for (auto change : changes){
                string future = cur;
                future[i] = change;
                if (validGenes.count(future) && !reach.count(validGenes[future])){
                    reach.insert(validGenes[future]);
                    dfs(future, end, reach, step + 1);
                    reach.erase(validGenes[future]);
                }
            }
        }
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int index = 0;
        for (auto gene: bank){
            validGenes[gene] = index++;
        }
        res = -1;
        unordered_set<int> reach;
        dfs(start,end,reach, 0);
        return res;
    }
};