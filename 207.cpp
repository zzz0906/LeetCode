class Solution {
public:
    unordered_map<int, vector<int>> graph_map;
    bool flag[100005];
    bool ans = false;
    void dfs(int cur){
        if (graph_map.count(cur) == 0) return;
        if (flag[cur] == true) {ans = false; return;}
        flag[cur] = true;
        for (int i = 0; i < graph_map[cur].size(); i++)
            dfs(graph_map[cur][i]);
        flag[cur] = false;
        if (ans == false) return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int maxn = INT_MIN;
        ans = true;
        for (int i = 0; i < prerequisites.size(); i++){
            if (graph_map.count(prerequisites[i][0]) == 0){
                vector<int> tmp; tmp.push_back(prerequisites[i][1]);
                graph_map[prerequisites[i][0]] = tmp;
            }else
                graph_map[prerequisites[i][0]].push_back(prerequisites[i][1]);
            if (prerequisites[i][0] > maxn) maxn = prerequisites[i][0];
        }
        
        for (auto &v : graph_map){
            dfs(v.first);
            if (ans == false) return false;
        }
        return true;
    }
};