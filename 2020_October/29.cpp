class Solution {
public:
    int max(int x,int y){
        return x>y?x:y;
    }
    int maxDistToClosest(vector<int>& seats) {
        int last = -1;
        int ans = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1 && last != -1 && i != last+1) {
                ans = max(ans,int((i-last)/2));
                last = i;
            }
            if (seats[i] == 1 && last == -1){
                ans = max(ans,i);
                last = i;
            }
            if (seats[i] == 1 && i == last + 1){
                last = i;
            }
            if (i == seats.size()-1 && seats[i] == 0)
                ans = max(ans,seats.size()-1-last);
        }
        return ans;
    }
};