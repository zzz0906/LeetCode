class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.size() == 1){
            if ((data[0] >> 7 & 1) == 1)
                return false;
            else
                return true;
        }else{
            int index = 0;
            while (index < data.size()){
                int nums = 0;
                int offset = 7;
                while (offset >= 0 && (data[index] >> offset & 1) == 1){
                    nums ++;
                    offset--;
                }
                if (nums > 4)
                    return false;
                for (int i = index + 1; i < index + nums; i++){
                    if (i >= data.size()) return false;
                    if ((data[i] >> 7 & 1) != 1 || (data[i] >> 6 & 1) != 0) return false;
                }
                if (nums == 0)
                    index ++;
                if (nums == 1)
                    return false;
                if (nums > 0)
                    index += nums;
            }
        }
        return true;
    }
};