//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /**
        Since the order of words can be in any form in the given string.
        1. Create a lookup table for each word and there count.
        2. There may be a case same word is repitative in the given words list.
        3. Next start from index 0 and check a sub-str of given word length is found in the lookup table. If so decrement the counter for that in the lookup table.
        4. Once all words in lookup table is found, update the index accordingly.
        **/
        vector<int> result;
        if ( s.empty() || words.empty()) {
            return result;
        }
        const int wLen = words[0].size();
        const int totalWordsLength = words.size() * wLen;
        
        if ( totalWordsLength > s.size()) {
            return result;
        }
        // Create a lookup table for all words.
        unordered_map<string, int> wLookup;
        
        for(auto word : words) {
            wLookup[word]++;
        }
        
        for(int i = 0 ; i <= s.size() - totalWordsLength; i++) {
            auto cLookup = wLookup;
            int cStart = i;
            while(!cLookup.empty() && cStart < s.size()) {
                string cStr = s.substr(cStart,wLen);
                auto it = cLookup.find(cStr);
                if ( it != cLookup.end()) {
                    it->second -= 1;
                    if ( it->second == 0 ) {
                        cLookup.erase(it);
                    }
                    cStart += wLen;                    
                } else {
                    break;
                }
            }
            
            // Check if cLookup is empty. then update the result and i.
            if ( cLookup.empty()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
