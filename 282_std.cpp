class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helper(num, target, 0, 0, "", res);
        return res;
    }
    void helper(string num, int target, long diff, long curNum, string out, vector<string>& res) {
        if (num.size() == 0 && curNum == target) {
            res.push_back(out); return;
        }
        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if (out.size() > 0) {
                helper(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                helper(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                helper(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
            } else {
                helper(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
    }
};