class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int sum = 0;
        int largest = 0;
        priority_queue<int> heap_dif;
        for (int i = 1; i < heights.size(); i++){
            if (heights[i] - heights[i - 1] > 0){
                sum += heights[i] - heights[i - 1];
                // largest = max(largest, heights[i] - heights[i - 1]);
                heap_dif.push(heights[i] - heights[i - 1]);
                if (sum > bricks){
                    if (ladders == 0){
                        return i-1;
                    }else{
                        sum -= heap_dif.top();
                        heap_dif.pop();
                        ladders --;
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};