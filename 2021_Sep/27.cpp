class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> nonDupEmails;
        for (string email : emails) {
            string name;
            for (char c : email) {
                if (c == '.')
                    continue;
                if (c == '+' || c == '@')
                    break;
                name += c;
            }

            name += email.substr(email.find('@'));
            nonDupEmails.insert(name);
        }
        return nonDupEmails.size();
    }
};