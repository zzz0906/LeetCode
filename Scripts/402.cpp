class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack = "";
        int tmp = k;
        for (char c : num){
            while (stack.length() > 0 && k > 0 && stack.back() > c){
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        stack.resize(num.length() - tmp);
        while (!stack.empty() && stack[0] == '0') stack.erase(stack.begin());
        return stack.empty() ? "0" : stack;
    }
};