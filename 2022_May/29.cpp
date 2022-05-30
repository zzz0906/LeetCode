class Solution {
public:
	// function to get the decimal value of respective string
    int getDecimalValue(string s) {
        int num = 0;
        for (char c : s) {
            num |= 1 << (c - 'a');
        }
        // cout << num << endl;
        return num;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        
		// if size of array is one then we can't take product hence result = 0
        if (n<2) return 0;
        
		// array to store the value of string converted decimal value
        vector<int> arr(n);
        
        for (int i = 0; i<n; i++) {
            arr[i] = getDecimalValue(words[i]);
        }
        
		// the two for loops to check for the maximum product
        int res = 0;
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
			
				// when arr[i]&arr[j] == 0 then they don't contain same lettter
				// hence multiplying their length
                if ((arr[i]&arr[j]) == 0) res = max(res, (int)words[i].size() * (int)words[j].size());
            }
        }
        
        return res;
    }
};