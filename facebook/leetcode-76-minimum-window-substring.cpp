#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(unordered_map<char, int>& tMap, unordered_map<char, int>& windowMap) {
        for(const auto &kvp : tMap) {
            if(windowMap.find(kvp.first) == windowMap.end() || 
            windowMap[kvp.first] < kvp.second)
                return false;
        }
        return true;
    }

    string helper(queue<char> window) {
        string res;
        while(!window.empty()) {
            res += window.front();
            window.pop();
        }
        return res;
    }

    string minWindow(string s, string t) {
        queue<char> window;
        unordered_map<char, int> windowMap;
        unordered_map<char, int> tMap;
        for(const auto c : t) tMap[c]++;
        
        int left = 0, right = 0;
        int count = 0;
        string res;

        // create window:
        while(left < s.size() && tMap.find(s[left]) == tMap.end()) left++;
        for(right = left; right < s.size(); ++right) {
            if(tMap.find(s[right]) != tMap.end() && tMap[s[right]] > windowMap[s[right]]) {
                count++;
            }
            window.push(s[right]);
            windowMap[s[right]]++;
            res += s[right];
            if(count == t.size()) break;
        }
        if(!isValid(tMap, windowMap))
            return "";

        while(left < s.size() && right < s.size()) {
            char c = window.front();
            windowMap[c]--;
            window.pop();
            left++;
            
            // sliding left side of window
            while(!window.empty() && left < s.size() && tMap.find(window.front()) == tMap.end()) {
                windowMap[window.front()]--;
                window.pop();
                left++;
            }

            // sliding right side of window
            if(windowMap[c] < tMap[c]) { // only advance right if needed
                right++;
                window.push(s[right]);
                windowMap[s[right]]++;
                while(right < s.size() && s[right] != c) {
                    right++;
                    window.push(s[right]);
                    windowMap[s[right]]++;
                }

            }

            // check if is valid
            if(isValid(tMap, windowMap) && window.size() < res.size()) {
                // compare window w/ res
                queue<char> tmpQueue = window;
                string tmpStr;
                while(!tmpQueue.empty()) {
                    tmpStr += tmpQueue.front();
                    tmpQueue.pop();
                }
                res = tmpStr;
            }

        }
        return res;
    }
};