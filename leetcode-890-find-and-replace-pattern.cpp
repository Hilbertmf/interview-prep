// time: O(# words * (word size + pattern size))
// space: O(# words + word size + pattern size)
class Solution {
public:
    bool hasMatch(string& word, string& pattern) {
        unordered_map<char, char> wordMap;
        unordered_map<char, char> patternMap;
        for(int i = 0; i < word.size(); ++i) {
            if(wordMap.find(word[i]) == wordMap.end() && patternMap.find(pattern[i]) == patternMap.end()) {
                wordMap[word[i]] = pattern[i];
                patternMap[pattern[i]] = word[i];
            }
            else {
                if(wordMap.find(word[i]) == wordMap.end() ||
                patternMap.find(pattern[i]) == patternMap.end() ||
                wordMap[word[i]] != pattern[i] || patternMap[pattern[i]] != word[i])
                    return false;
            }
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto &word : words) {
            if(hasMatch(word, pattern)) res.push_back(word);
        }
        return res;
    }
};
