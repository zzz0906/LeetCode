class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool flag = true;
        bool has_up = false;
        bool has_down = false;
        for (int i = 1; i < arr.size(); i++){
            if (flag) {
                if(arr[i] <= arr[i-1])
                    flag = false;
                else
                    has_up = true;
            } 
            else{
                if(arr[i] >= arr[i-1])
                    return false;
            }
        }
        if (has_up == false || flag || arr[arr.size()-1] == arr[arr.size()-2]) return false;
        return true;       
    }
};