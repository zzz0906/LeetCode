class Solution {
public:
    vector<int> constructRectangle(int area) {
        int end = sqrt(area);
        while (area % end != 0){
            end --;
        }
        return {area / end, end};
    }
};