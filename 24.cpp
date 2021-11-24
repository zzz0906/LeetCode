class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int st1 = 0; int st2 = 0;
        vector<vector<int>> res;
        while (st1 < firstList.size() && st2 < secondList.size()){
            if (firstList[st1][0] <= secondList[st2][1] && firstList[st1][0] >= secondList[st2][0]){
                res.push_back({firstList[st1][0], min(firstList[st1][1], secondList[st2][1])});
            }else if (firstList[st1][1] <= secondList[st2][1] && firstList[st1][1] >= secondList[st2][0]){
                res.push_back({max(firstList[st1][0], secondList[st2][0]), firstList[st1][1]});
            }else if (firstList[st1][0] < secondList[st2][0] && firstList[st1][1] > secondList[st2][1]){
                res.push_back({secondList[st2][0], secondList[st2][1]});
            }
            if (firstList[st1][1] <= secondList[st2][1]){
                st1 ++;
            }else{
                st2 ++;
            }
        }
        return res;
    }
};