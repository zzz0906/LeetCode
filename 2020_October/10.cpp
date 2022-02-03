class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        int res = 1; int end = points[0].second;
        for (int i = 1; i < points.size(); i++){
            if (points[i].first <= end){
                end = min(end, points[i].second);
            }else{
                res++;
                end = points[i].second;
            }
        }
        return res;
    }
};