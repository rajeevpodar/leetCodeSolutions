//https://leetcode.com/problems/short-encoding-of-words/
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        /**
        Idea is to add a word and check if added word is suffix of any other word
        then that word need to be added at all.
        Sort the words in descending order of there length, to ensure bigger word added first,
        and if there is any suffix word that can be skipped if possible.
        e.g.["me","time"], here time should be considered first for processing. o/p time#
        **/
        string result;
        unordered_set<string> lookup(words.begin(), words.end());
        // Sort the data in descending order of there length.
        sort(words.begin(), words.end(),[](const string& s1, const string&s2) {return s1.length() > s2.length();});
        for(auto word : words) {
            //Check if the word exists in lookup data, then that is not yet added.
            if ( lookup.find(word) != lookup.end()) {
                result += word;
                // Check for each sub string for the current word,
                // it exists in the lookup then remove that no need to add that.
                for(int i = 0 ; i < word.size(); i++) {
                    string current = word.substr(i);
                    if ( lookup.find(current) != lookup.end()) {
                        lookup.erase(current);
                    }
                }
                result += "#";
            }
        }
        return result.size();
    }
};
