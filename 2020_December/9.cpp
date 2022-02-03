class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for (int i = 0; i < time.size(); i++)
            time[i] %= 60;
        int ans = 0;
        sort(time.begin(), time.end);
        int i = 0, j = time.size() - 1;
        while (i < time.size() && time[i] == 0) i++;
        ans = i*(i-1)/2;
        while (i < j){
            if (time[i] + time[j] > 60) j--;
            if (time[i] + time[j] < 60) i++;
            if (time[i] + time[j] == 60){
                if (time[i] == 30){
                    ans += (j-i+1)*(j-i)/2;
                    break;
                }
                if (i + 1 == j){
                    ans += 1;
                    break;
                }
                int count1 = 1;
                i++;
                while (i < j && time[i] == time[i-1]) {i++;count1++;}
                int count2 = 1;
                j--;
                while (j > i && time[j] == time[j+1]) {j--;count2++;};
                ans += count1*count2;
            }
        }
        return ans;
    }
};