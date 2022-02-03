class Solution {
public:
    vector<vector<int>> rects;
    vector<int> acc_weights;
    int area_total = 0;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for (auto rect : rects){
            area_total += (rect[2]-rect[0] + 1) * (rect[3] - rect[1] + 1);
            this->acc_weights.push_back(area_total);
        }
    }
    
    vector<int> pick() {
        int w = rand() % area_total;
        int left = 0, right = acc_weights.size(), mid;

        while(left != right) {
            mid = (left+right)/2;
            if (w >= acc_weights[mid]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        return pickRandomPoint(rects[left]);
    }

    vector<int> pickRandomPoint(vector<int> rect) {
        int x = rand() % (rect[2] - rect[0] + 1);
        int y = rand() % (rect[3] - rect[1] + 1);
        return {rect[0] + x, rect[1] + y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */