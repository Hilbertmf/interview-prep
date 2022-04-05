class Solution {
public:
  bool hasMatch(char c1, char c2) {
    return c1 == '(' && c2 == ')';
  }
  
  string minRemoveToMakeValid(string s) {
    stack<pair<char, int>> parenthesesStack;
    string res = "";
    unordered_set<int> idxsToRemove;
    
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '(' || s[i] == ')') {
        if(!parenthesesStack.empty() && 
           hasMatch(parenthesesStack.top().first, s[i])) {
          parenthesesStack.pop();
        }
        else {
          parenthesesStack.push(make_pair(s[i], i));
        }
      }
    }
    
    while(!parenthesesStack.empty()) {
      idxsToRemove.insert(parenthesesStack.top().second);
      parenthesesStack.pop();
    }
    
    for(int i = 0; i < s.size(); i++) {
      if(idxsToRemove.find(i) == idxsToRemove.end()) { // !contains
        res += s[i];
      }
    }
    
    return res;
  }
};
/*
in:  "))(("
          |
curr:  
stack: [),0] [),1] [(,2] [(,3]
hashset: 0 1 2 3
i=0
time: O(n)
space: O(n)
*/