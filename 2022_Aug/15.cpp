class Solution {
public:
    int romanToInt(string s) {
        //Map to store values of roman numbers
        unordered_map<char, int>map = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0, i=0, n = s.size();
        
		
        while(i<n){
			// If current character has a lower value than the next character, subtract its value from ans
            if(map[s[i]] < map[s[i+1]])
                ans -= map[s[i]];
			//Else add to ans
            else
                ans += map[s[i]];          
            i++;
        }
        return ans;
    }
};