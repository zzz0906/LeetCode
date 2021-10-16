class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),[](vector<int> &a, vector<int> &b){
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int last = 0;
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[last][1]){
                res++;
                last = i;   
            }else{
                points[last][1] = min(points[last][1],points[i][1]);
            }
        }
        // the last group
        res++;
        return res;
        
    }
};