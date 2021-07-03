class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end());
        vector<int>::iterator upper;
        upper = upper_bound(arr.begin(), arr.end(), x);
        int pos = upper - arr.begin();
        if (pos == arr.size())
            pos--;
        if (arr[pos] > x && pos > 0){
            if (abs(x - arr[pos - 1]) < abs(x - arr[pos])){
                pos--;
            }else if (abs(x - arr[pos - 1]) == abs(x - arr[pos]) && arr[pos - 1] < arr[pos]){
                pos--;
            }
        }
        int left = 1;
        int right = 1;
        vector<int> res; 
        res.push_back(arr[pos]);
        //cout<<pos<<endl;
        while (k > 1){
            if (pos - left < 0){
                res.push_back(arr[pos + right]);
                right ++; k --;
            }else if (pos + right >= arr.size()){
                res.push_back(arr[pos - left]);
                left++; k--;
            }else{
                if (abs(x - arr[pos + right]) < abs(x - arr[pos - left])){
                    res.push_back(arr[pos + right]);
                    right++;
                }else if (abs(x - arr[pos + right]) > abs(x - arr[pos - left])){
                    res.push_back(arr[pos - left]);
                    left++;
                }else{
                    if (arr[pos + right] < arr[pos - left]){
                        res.push_back(arr[pos + right]);
                        right++;
                    }else{
                        res.push_back(arr[pos - left]);
                        left++;
                    }
                }
                //cout << left << right << endl;
                k--;
            }
            //cout << left << right << endl;
        }
        sort(res.begin(),res.end());
        return res;
    }
};