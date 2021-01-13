class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        cout<<heights.size()<<endl;
        int minumum = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            int right = i;
            while (left > 0 && heights[left] >= heights[i]) left--;
            if (heights[left] < heights[i]) left++;
            while (right < heights.size()-1 && heights[right] >= heights[i]) right++;
            if (heights[right] < heights[i]) right--;
            int current_area = (right-left+1)*heights[i];
            if (current_area > minumum){
                cout<<left<<" "<<right<<endl;
                minumum = current_area;
            }
        }
        return minumum;
    }
};