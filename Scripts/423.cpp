string originalDigits(string s) {
        unordered_map<char,int> m;
        for(auto c : s) {
            m[c]++;
        }
        
        string ans = "";
        
        //check zeros using 'z'
        if(m['z'] > 0) {
            int mult = m['z'];
            string zeros(mult,'0');
            ans += zeros;
            m['z'] -= mult; m['e'] -= mult; m['r'] -= mult; m['o'] -= mult;
        }
        
        //check twos using 'w'
        if(m['w'] > 0) {
            int mult = m['w'];
            string twos(mult,'2');
            ans += twos;
            m['t'] -= mult; m['w'] -= mult; m['o'] -= mult;
        }
        
        //check fours using 'u'
        if(m['u'] > 0) {
            int mult = m['u'];
            string fours(mult,'4');
            ans += fours;
            m['f'] -= mult; m['o'] -= mult; m['u'] -= mult; m['r'] -= mult;
        }
        
        //after including fours, 'f' is unique only to five
        if(m['f'] > 0) {
            int mult = m['f'];
            string fives(mult,'5');
            ans += fives;
            m['f'] -= mult; m['i'] -= mult; m['v'] -= mult; m['e'] -= mult;
        }
        
        //after including zeros and fours, 'r' is unique only to three
        if(m['r'] > 0) {
            int mult = m['r'];
            string threes(mult,'3');
            ans += threes;
            m['t'] -= mult; m['h'] -= mult; m['r'] -= mult; m['e'] -= (2*mult);
        }
        
        //after including zeros, twos and fours, 'o' is unique only to one
        if(m['o'] > 0) {
            int mult = m['o'];
            string ones(mult,'1');
            ans += ones;
            m['o'] -= mult; m['n'] -= mult; m['e'] -= mult;
        }
        
        //after inlcuding five, 'v' is uniue to seven
        if(m['v'] > 0) {
            int mult = m['v'];
            string sevens(mult,'7');
            ans += sevens;
            m['s'] -= mult; m['e'] -= (2*mult); m['v'] -= mult; m['n'] -= mult;
        }
        
        
        //after including three, 'h' is unique to eight
        if(m['h'] > 0) {
            int mult = m['h'];
            string eights(mult,'8');
            ans += eights;
            m['e'] -= mult; m['i'] -= mult; m['g'] -= mult; m['h'] -= mult; m['t'] -= mult;
        }
        
        //after including seven, 'n' is unique to nine
        if(m['n'] > 0) {
            int mult = m['n']/2;
            string nines(mult,'9');
            ans += nines;
            m['n'] -= (2*mult); m['i'] -= mult; m['e'] -= mult;
        }
        
        //finally, check sixes using 'x'
        if(m['x'] > 0) {
            int mult = m['x'];
            string sixes(mult,'6');
            ans += sixes;
            m['s'] -= mult; m['i'] -= mult; m['x'] -= mult;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }