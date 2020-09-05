class Solution {
public:
    vector<int> partitionLabels(string S) {
        int first[27];
        int last[27];
        for (int i = 0; i < 26; i++) last[i] = -1;
        for (int i = 0; i < 26; i++) first[i] = INT_MAX;
        for (int i = 0; i < S.length();i++){
            last[S[i]-'a'] = i;
            first[S[i]-'a'] = min(i,first[S[i]-'a']);
        }
        int begin = 0;
        vector<int> answer;
        while (begin < S.length()){
            for (int i = 0; i < 26; i++) 
                if (first[i] == begin){
                    int end = last[i];
                    first[i] = -1;
                    last[i] = -1;
                    while (true){
                        bool flag = true;
                        for (int j = 0; j < 26; j++){
                            if (first[j] > begin && first[j] < end) {
                                end = max(end, last[j]);
                                last[j] = -1;
                                first[j] = -1;
                                flag = false;
                            }
                        }
                        if (flag) break;
                    }
                    answer.push_back(end-begin+1);
                    begin = end+1;
                    break;
                }
        }
        return answer;
    }
};