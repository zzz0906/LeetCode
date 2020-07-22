class Solution {
public:
    vector<vector<string>> bfs_queue;
    vector<unordered_set<string>> records;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> path;
        unordered_set<string> record;
        record.insert(beginWord);
        records.push_back(record);
        path.push_back(beginWord);
        bfs_queue.push_back(path);
        int minLen = INT_MAX;
        int leftpoint = 0;
        vector<vector<string>> answer;
        while (leftpoint < bfs_queue.size()) {
            vector<string> path = bfs_queue[leftpoint];
            unordered_set<string> record = records[leftpoint];
            leftpoint ++;
            if (path[path.size()-1] == endWord){
                if (path.size() <= minLen){
                   answer.push_back(path);
                   minLen = path.size();
                   continue;
                }
                continue;
            }
            if (path.size() > minLen) break;
            for (int i = 0; i < wordList.size(); i++){
                int diffcount = 0;
                if (record.find(wordList[i]) != record.end())
                    continue;
                for (int j = 0; j < wordList[i].size(); j++){
                    if (wordList[i][j] != path[path.size()-1][j]) diffcount++;
                    if (diffcount > 1) break;
                }
                if (diffcount == 1){
                    vector<string> vtmp = path;
                    vtmp.push_back(wordList[i]);
                    if (vtmp.size() <= minLen){
                        unordered_set<string> rtmp = record;
                        rtmp.insert(wordlist[i]);
                        bfs_queue.push_back(vtmp);
                        records.push_back(rtmp);
                }
            }
        }
        vector<vector<string>> shortanswer;
        for (int i = 0; i <answer.size();i++)
            if (answer[i].size() == minLen) shortanswer.push_back(answer[i]);
        return shortanswer;
    }
};