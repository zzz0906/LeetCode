class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int st = -1;
        for (int i = 0; i < intervals.size(); i++){
            if (newInterval[0] <= intervals[i][1]){
                st = i;
                break;
            }
        }
        int ed = -1;
        for (int i = st+1; i < intervals.size(); i++){
            if (newInterval[1] < intervals[i][0]) ed = i;
        }
        vector<vector<int>> answer = intervals;
        if (st == -1) {answer.push_back(newInterval);return answer;}
        if (ed == -1) {
            if (newInterval[1] < intervals[st][0]){
                answer.insert(answer.begin()+st,newInterval);
                return answer;
            }
            vector<int> newel; 
            newel.push_back(min(intervals[st][0],newInterval[0])); 
            newel.push_back(max(newInterval[1],max(intervals[st][1],intervals[intervals.size()-1][1]))); 
            while (st < intervals.size()){st++; answer.pop_back();} 
            answer.push_back(newel); 
            return answer;
        }
        int tmp_left = intervals[ed-1][1];
        cout<<tmp_left<<endl;
        if (newInterval[1] >= intervals[ed][0]) tmp_left = max(intervals[ed][1],tmp_left);
        // 3 4
        vector<int> newel; 
        newel.push_back(min(intervals[st][0],newInterval[0]));
        for (int i = st; i < ed;i++){
            answer.erase(answer.begin() + st);
        }
        newel.push_back(max(tmp_left,newInterval[1]));
        answer.insert(answer.begin()+st,newel);
        return answer;
    }
};