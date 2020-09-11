class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);
        bool flag[nums.size()];
        memset(flag, 0, sizeof(flag));
        string maxx = "0";
        for (int i = 0; i < nums.size();i++){
            for (int i = 1; i < nums.size(); i++)
                if (flag[i] != true) {
                    string current = to_string(nums[i]);
                    index = 0;
                    int stopf = 0;
                    while (index < current.length() && index < maxx.length()){
                        if ((current[index]-'0') > (maxx[index]-'0')){
                            maxx = current;
                            stopf = 1;
                            break;
                        }
                        if ((current[index]-'0') < (maxx[index]-'0')){
                            stopf = 2;
                            break;
                        }
                    }
                    if (stopf == 0){
                        //if two current number equals
                        //31 315 we need to choose 315; however when 91 915 we need to choose 915; but if there is a 9 in the number we need to choose 9;
                        
                    }
                }
        }
    }
};