class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() <= 1){
            return chars.size();
        }
        int last = chars[0];
        int lastCount = 1;
        int index = 0;
        for (int i = 1; i < chars.size(); i++){
            if (chars[i] == last){
                lastCount++;
            }else{
                if (lastCount == 1){
                    chars[index] = last;
                    index += 1;
                }else{
                    chars[index] = last;
                    int start = 1;
                    for (auto c : to_string(lastCount)){
                        chars[index + start] = c;
                        start ++;
                    }
                    index += start;
                }
                lastCount = 1;
                last = chars[i];
            }
        }
        if (lastCount == 1){
            chars[index] = last;
            index += 1;
        }else{
            chars[index] = last;
            int start = 1;
            for (auto c : to_string(lastCount)){
                chars[index + start] = c;
                start ++;
            }
            index += start;
        }

        return index;
    }
};