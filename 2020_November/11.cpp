class Solution {
public:
    double distance(int x1, int y1, int x2, int y2){
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //p1 p2 p3; p1 p3 p4; p1 p2 p4;
        if (distance(p1[0],p1[1],p2[0],p2[1]) == 0 || distance(p1[0],p1[1],p3[0],p3[1]) == 0 || distance(p1[0],p1[1],p4[0],p4[1]) == 0 || distance(p2[0],p2[1],p3[0],p3[1]) == 0 || distance(p2[0],p2[1],p4[0],p4[1]) == 0 || distance(p3[0],p3[1],p4[0],p4[1]) == 0)
            return false;
        double tmp = distance(p1[0],p1[1],p2[0],p2[1]);
        if (tmp == distance(p1[0],p1[1],p3[0],p3[1]) && tmp == distance(p2[0],p2[1],p4[0],p4[1]) && tmp == distance(p4[0],p4[1],p3[0],p3[1]) && distance(p1[0],p1[1],p4[0],p4[1]) == distance(p2[0],p2[1],p3[0],p3[1]))
            return true;
        tmp = distance(p1[0],p1[1],p3[0],p3[1]);
        if (tmp == distance(p1[0],p1[1],p4[0],p4[1]) && tmp == distance(p2[0],p2[1],p4[0],p4[1]) && tmp == distance(p2[0],p2[1],p3[0],p3[1]) && distance(p3[0],p3[1],p4[0],p4[1]) == distance(p1[0],p1[1],p2[0],p2[1]))
            return true;
        tmp = distance(p1[0],p1[1],p2[0],p2[1]);
        if (tmp == distance(p1[0],p1[1],p4[0],p4[1]) && tmp == distance(p3[0],p3[1],p4[0],p4[1]) && tmp == distance(p3[0],p3[1],p2[0],p2[1]) && distance(p1[0],p1[1],p3[0],p3[1]) == distance(p2[0],p2[1],p4[0],p4[1]))
            return true;
        return false;
    }
};