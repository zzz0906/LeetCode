class Solution {
public:
	bool isNumber(string s) {
		enum InputType {
			INVALID,		// 0 Include: Alphas, '(', '&' ans so on
			SPACE,		// 1
			SIGN,		// 2 '+','-'
			DIGIT,		// 3 numbers
			DOT,			// 4 '.'
			EXPONENT,		// 5 'e' 'E'
		};
		int transTable[][6] = {
		//0INVA,1SPA,2SIG,3DI,4DO,5E
			-1,  0,  3,  1,  2, -1,//0初始无输入或者只有space的状态
			-1,  8, -1,  1,  4,  5,//1输入了数字之后的状态
			-1, -1, -1,  4, -1, -1,//2前面无数字，只输入了Dot的状态
			-1, -1, -1,  1,  2, -1,//3输入了符号状态
			-1,  8, -1,  4, -1,  5,//4前面有数字和有dot的状态
			-1, -1,  6,  7, -1, -1,//5'e' or 'E'输入后的状态
			-1, -1, -1,  7, -1, -1,//6输入e之后输入Sign的状态
			-1,  8, -1,  7, -1, -1,//7输入e后输入数字的状态
			-1,  8, -1, -1, -1, -1,//8前面有有效数输入之后，输入space的状态
		};
		int state = 0;
        int i = 0;
		while (i < s.size())
		{
			InputType input = INVALID;
			if (s[i] == ' ') input = SPACE;
			else if (s[i] == '+' || s[i] == '-') input = SIGN;
			else if (isdigit(s[i])) input = DIGIT;
			else if (s[i] == '.') input = DOT;
			else if (s[i] == 'e' || s[i] == 'E') input = EXPONENT;
			state = transTable[state][input];
			if (state == -1) return false;
			++i;
		}
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};