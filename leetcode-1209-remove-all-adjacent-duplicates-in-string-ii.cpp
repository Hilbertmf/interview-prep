// solved (AC)
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
class Solution {
public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> char_stack;
    string resString = "";
    for(auto c : s) {
      if(!char_stack.empty() && c == char_stack.top().first) {
        char_stack.top().second++;    
        if(char_stack.top().second == k) {
          char_stack.pop();
        }
      }
      else {
        char_stack.push(make_pair(c, 1));
      }
    }
    while(!char_stack.empty()) {
      // concatenate the number of times the char repeats
      for(int i = 0; i < char_stack.top().second; i++) {
        resString += char_stack.top().first;
        // resString = char_stack.top().first + resString;//memory exceeded
      }
      char_stack.pop();
    }
    std::reverse(resString.begin(), resString.end());
    return resString;
  }
};