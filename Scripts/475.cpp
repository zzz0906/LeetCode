class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(), heaters.end());
        int right = max(houses.back(),heaters.back()) - min(heaters.front(),houses.front());
        int left = 0;
        while (left < right){
            cout << left << right << endl;
            int middle = left + (right - left) / 2;
            
            int index = 0;
            bool cover = true;
            for (auto heater : heaters){
                if (index == houses.size()){
                    break;
                }
                if (heater - middle > houses[index]){
                    cover = false;
                    break;
                }
                
                while (index < houses.size() && houses[index] <= heater + middle)
                    index++;
            }
            if (cover && index >= houses.size()){
                right = middle;
            }else{
                left = middle + 1;
            }
        }
        return right;
    }
};