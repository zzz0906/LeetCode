class Solution {
private:
    int radius;
    int x_center;
    int y_center;
    std::random_device _rd{};
    std::uniform_real_distribution<double> _distx;
    std::uniform_real_distribution<double> _disty;
    std::mt19937 _gen{_rd()};
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        std::uniform_real_distribution<double>::param_type paramx(x_center - radius, x_center + radius);
        _distx.param(paramx);
        std::uniform_real_distribution<double>::param_type paramy(y_center - radius, y_center + radius);
        _disty.param(paramy);
    }
    
    vector<double> randPoint() {
        double rx = _distx(_gen);
        double ry = _disty(_gen);

        if (sqrt((rx - x_center)*(rx - x_center) + (ry - y_center)*(ry - y_center)) > radius){
            return randPoint();
        }
        return {rx,ry};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */