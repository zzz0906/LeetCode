class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> value;
        int index = 0;
        while (index < tokens.size() && tokens[index] != "+" && tokens[index] != "-" && tokens[index] != "*" && tokens[index] != "/"){
            value.push(stoi(tokens[index]));
            index++;
        }
        while (index < tokens.size()){
            if (tokens[index] != "+" && tokens[index] != "-" && tokens[index] != "*" && tokens[index] != "/"){
                value.push(stoi(tokens[index]));
            }
            else{
                int a = value.top();value.pop();
                int b = value.top();value.pop();
                if (tokens[index] == "+") value.push(a+b);
                if (tokens[index] == "-") value.push(b-a);
                if (tokens[index] == "*") value.push(a*b);
                if (tokens[index] == "/") {value.push(b/a);}
            }
            index++;
        }
        return value.top();
    }
};