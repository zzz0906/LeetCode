class Solution {
	// function to remove a word from usedWords hasmap
    void remove(unordered_map<string, int> &hashmap, string &key)
    {
        hashmap[key]--;
        if(hashmap[key] <= 0)
            hashmap.erase(key);
    }
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordDict;
        unordered_map<string, int> usedWords;
        int word_len = words[0].length(), total_words = words.size();
        int left = 0, right = 0, n = s.length();
        int words_used = 0;
        vector<int> ans;
        
		// wordDict contains all words with their frequencies
        for(auto &word: words)
            wordDict[word]++;
        
		// We iterate staring from every index in range [0, word_len] to get every possible combination
        for(int i=0; i<word_len; i++)
        {
			// right pointer is used to expand the current window and 
			// left pointer is used to shrink the current window whenever the window becomes invalid
            left = i, right = i;
            usedWords.clear();
            words_used = 0;
			
			// We start iterating till end of string
			// Once we pick a word of length 'word_len' then we go to next index = 'right + word_len'
            while(right < n)
            {
                auto curr = s.substr(right, min(n-right, word_len));
                
				// If the curr picked word does not exist in the words array given to us then the current window is no longer usefull and so we discard all the words we have used untill now and increment our right and left pointer to point to the next word in sequence
                if(wordDict.find(curr) == wordDict.end())
                {
                    usedWords.clear();
                    words_used = 0;
                    right += word_len;
                    left = right;
                    continue;
                }
                
				// If freq of curr word is less then required freq of that word we can add it to our usedWords and also increment the no of words that we have used in the current window
                if(usedWords[curr] < wordDict[curr])
                    usedWords[curr]++, words_used++;
				// If the freq gets higher then we start removing words from the begining of window until the window becomes valid again
                else
                {
                    while(left < right)
                    {
                        auto to_remove = s.substr(left, word_len);
                        remove(usedWords, to_remove);
                        words_used--;
                        left += word_len;
                        if(usedWords[curr] < wordDict[curr])
                            break;
                    }
					// Now the window has becomes valid so we can add the curr word to the usedWords
                    usedWords[curr]++, words_used++;
                }
                right += word_len;
				
				// if the words of our current window get equal to the total words required the we can add the index of the starting of the window(left pointer) to our answer array and move the left pointer one step forward.
				// We cant set the left pointer to point to right because we might have an answer starting from 'left+word_len'. So we only increment it one step forward.
                if(words_used == total_words)
                {                    
                    ans.push_back(left);
                    auto to_remove = s.substr(left, word_len);
                    remove(usedWords, to_remove);
                    words_used--;
                    left += word_len;
                }
            
            }
        }
        return ans;
    }
};