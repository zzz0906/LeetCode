class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,list<string>> linkedlist;
        map<string,int> inorder;
        int number_of_city = 1;
        for (int i = 0; i < tickets.size(); i++){
            if (inorder.count(tickets[i][1]))
                inorder[tickets[i][1]]++;
            else
                inorder[tickets[i][1]] = 1;
            linkedlist[tickets[i][0]].push_back(tickets[i][1]);
            if (tickets[i][1] == 'JFK')
                number_of_city = 0;
            //when JFK can be the target, which means inorder JFK has a number we shall let number of city be zero
        }
        number_of_city += inorder.size();
        //find all cities
        vector<string> res;
        res.push_back("JFK");

        vector<string> last_round;

        unordered_set<string> choosen;
        choosen.insert("JFK");

        list<int>:: it;
        for (it = linkedlist["JFK"].begin(); it != linkedlist["JFK"].end(); it++){
            inorder[*it] --;
            last_round.push_back(*it);
        }

        while (res.size() < number_of_city){
            int mini = INT_MAX;
            string city_choosen = 'unknown';
            for (auto s: last_round)
                if (inorder[s] < mini && !choosen.count(s)){
                    mini = inorder[s];
                    city_choosen = s;
                }
            
            res.push_back(city_choosen);
            choosen.insert(city_choosen);

            last_round.clear();
            for (it = linkedlist[city_choosen].begin(); it != linkedlist[city_choosen].end(); it++){
                inorder[*it] --;
                last_round.push_back(*it);
            }

        }

        return res;

    }
};