class Solution {
private:
    double radius, x_center, y_center;
    double fRand(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        // rand from x-radius,x+radius; y-radius,y+radius;
        vector<double> tmp;
        while (true){
            double x = fRand(this->x_center - this->radius, this->x_center + this->radius);
            double y = fRand(this->y_center - this->radius, this->y_center + this->radius);
            //cout << x << y << endl;
            if (sqrt((x - x_center)*(x - x_center) + (y - y_center)*(y - y_center)) <= this->radius){
                tmp.push_back(x);tmp.push_back(y);
                return tmp;
            }
        }
        return tmp;
    }
};