class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<vector<double> > distance(points.size(), vector<double>(points.size(), 0));
        unordered_map<int,unordered_map<double, int>> i2distance2j;
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++){
                if (i != j){
                    distance[i][j] = (double)sqrt((points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]));
                    
                    if (i2distance2j[i].count(distance[i][j])){
                        i2distance2j[i][distance[i][j]] += 1;
                    }else{
                        i2distance2j[i][distance[i][j]] = 1;
                    }

                    distance[j][i] = distance[i][j];
                    if (i2distance2j[j].count(distance[j][i])){
                        i2distance2j[j][distance[j][i]] += 1;
                    }else{
                        i2distance2j[j][distance[j][i]] = 1;
                    }
                }
            }
        int res = 0;
        for (int i = 0; i < points.size(); i ++)
            for (int j = 0; j < points.size(); j++)
                if (i != j){
                        res += (i2distance2j[i][distance[i][j]] - 1);
                    }
        return res;
    }
};