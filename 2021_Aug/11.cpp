class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<bool> select(arr.size(),false);
        int count = 0;
        int req = int(arr.size() / 2);
        
        for (int i=0; i < arr.size(); i++) {
            if (select[i])
                continue;
            
            vector<int>::iterator it_two_times = lower_bound(arr.begin() + i + 1, arr.end(),arr[i]*2);
            if (it_two_times != arr.end() && *it_two_times == arr[i]*2 && !select[it_two_times - arr.begin()]){
                count += 1;
                select[it_two_times - arr.begin()] = true;
            }
        }
        
        cout << count << endl;
        if (count == req)
            return true;
        else
            return false;
    }
};