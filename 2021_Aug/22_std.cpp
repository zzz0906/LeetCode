class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long res = 0, pre_x = 0, height = 0, start = 0, cnt = 0, M = 1e9 + 7;
        map<int, vector<pair<int, int>>> groupMap;
        map<int, int> cntMap;
        for (auto &a : rectangles) {
        	groupMap[a[0]].push_back({a[1], 1});
        	groupMap[a[0]].push_back({a[3], -1});
        	groupMap[a[2]].push_back({a[1], -1});
        	groupMap[a[2]].push_back({a[3], 1});
        }
        for (auto &group : groupMap) {
        	res = (res + (group.first - pre_x) * height) % M;
        	for (auto &a : group.second) {
        		cntMap[a.first] += a.second;
        	}
        	height = 0, start = 0, cnt = 0;
        	for (auto &a : cntMap) {
        		if (cnt == 0) start = a.first;
        		cnt += a.second;
        		if (cnt == 0) height += a.first - start;
        	}
        	pre_x = group.first;
        }
        return res;
    }
};