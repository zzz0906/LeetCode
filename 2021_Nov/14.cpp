class CombinationIterator {
private:
    set<string>combinations; // Our main set
    set<string>::iterator cur; // Pointer to our main set
public:
    CombinationIterator(string characters, int combinationLength) {
        
        int total = (1<<characters.size()); // Total subsets possible - 2^n
        
		// Iterate through all the subsets
        for(int mask{1}; mask<total; ++mask){
            
			// If length/ size of subset is not equal to combinationLength, then skip it
            if(__builtin_popcount(mask) != combinationLength)
                continue;
            
			//Now, we are sure that we have subset of desired length
            set<char>my_set; // stores characters of subset lexicographically
			
			// Iterate through every available character to determine whether next character is existed or not
            for(int i{}; i<characters.size(); ++i){
                
                int f = (1<<i);
                
				// If character exists in our subset, add it to our set which we will use to generate our string
                if(mask & f)
                    my_set.insert(characters[i]);
            }
            
           
            string st{};
			
			// Here we generate the string in lexicographical order
            for(auto c:my_set){
                st.push_back(c);
            }
			
			// And finally add it to our main set
            combinations.insert(st);
        }
        
		// Initialize the pointer of our set to pointing to the begining of our set
        cur = combinations.begin();
        
    }
    
	// Here returns the string which is pointed by current pointer and moves forward
    string next() {
        return *cur++;
    }
    
	// Check whether current pointer is pointing towards  end or not
    bool hasNext() {
        return cur != combinations.end();
    }
};