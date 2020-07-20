class Solution {
public:
    vector<string> realwordslist;
    string target;
    vector<vector<string>> answer;
    int minlen = INT_MAX;
    void dfs(unordered_set<string> record, vector<string> path){
        if (path.size() > minlen) return;
        if (path[path.size()-1] == target){
            answer.push_back(path);
            if (path.size() < minlen)
                minlen = path.size();
            return;
        }
        if (path.size() > realwordslist.size()) return;
        for (int i = 0; i < realwordslist.size(); i++){
            int diffcount = 0;
            for (int j = 0; j < realwordslist[i].size(); j++){
                if (realwordslist[i][j] != path[path.size()-1][j]) diffcount++;
            }
            if (diffcount == 1 && (record.find(realwordslist[i]) == record.end())){
                unordered_set<string> tmp = record;
                tmp.insert(realwordslist[i]);
                vector<string> vtmp = path;
                vtmp.push_back(realwordslist[i]);
                dfs(tmp,vtmp);
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        realwordslist = wordList;
        target = endWord;
        vector<string> path;
        path.push_back(beginWord);
        unordered_set<string> record;
        dfs(record, path);
        vector<vector<string>> shortanswer;
        for (int i = 0; i <answer.size();i++)
            if (answer[i].size() == minlen) shortanswer.push_back(answer[i]);
        return shortanswer;
    }
};