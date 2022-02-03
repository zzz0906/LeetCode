char tabl[10][10];
int tabll[10];
vector<string> answer;
void dfs(string digits,int now,string foranswer){
	if (now == digits.size()) {
		answer.push_back(foranswer);
		return;
	}
	for (int i = 0;i<tabll[digits[now] - '0'];i++)
		dfs(digits,now+1,foranswer+tabl[digits[now] - '0'][i]);
		
}
class Solution {
public:
    static vector<string> letterCombinations(string digits) {
    	answer.clear();
    	if (digits == "") return answer;
    	tabl[1][0] = ' ';tabll[1] = 1;
    	tabl[2][0] = 'a';tabl[2][1] = 'b';tabl[2][2] = 'c';tabll[2] = 3;
    	tabl[3][0] = 'd';tabl[3][1] = 'e';tabl[3][2] = 'f';tabll[3] = 3;
    	tabl[4][0] = 'g';tabl[4][1] = 'h';tabl[4][2] = 'i';tabll[4] = 3;
    	tabl[5][0] = 'j';tabl[5][1] = 'k';tabl[5][2] = 'l';tabll[5] = 3;
    	tabl[6][0] = 'm';tabl[6][1] = 'n';tabl[6][2] = 'o';tabll[6] = 3;
    	tabl[7][0] = 'p';tabl[7][1] = 'q';tabl[7][2] = 'r';tabl[7][3] = 's';tabll[7] = 4;
    	tabl[8][0] = 't';tabl[8][1] = 'u';tabl[8][2] = 'v';tabll[8] = 3;
    	tabl[9][0] = 'w';tabl[9][1] = 'x';tabl[9][2] ='y';tabl[9][3] = 'z';tabll[9] = 4;
    	dfs(digits,0,"");
    	return answer;
    }
};