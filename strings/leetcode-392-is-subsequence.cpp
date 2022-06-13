class Solution {
public:
    // time: O(s + t)
    // space: O(1)
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        
        for(int i = 0; i < t.size() && ptr < s.size(); ++i) {
            if(s[ptr] == t[i])
                ++ptr;
        }
        
        return ptr == s.size();
    }

    // follow up: if we have many queries we can use binary search on
    // indices:
    // time: O(t + slogt)
    // space: O(t)
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        unordered_map<char, vector<int>> indexMap;
        indexMap.reserve(26);
        for(int i = 0; i < t.size(); ++i)
            indexMap[t[i]].push_back(i);
        
        int prev = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(indexMap.find(s[i]) == indexMap.end())
                return false;
            auto vec = indexMap[s[i]];
            auto pos = upper_bound(vec.begin(), vec.end(), prev);
            if(pos == vec.end())
                return false;
            prev = *pos;
        }
        
        return true;
    }
};