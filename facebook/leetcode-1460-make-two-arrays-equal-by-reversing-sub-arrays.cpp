// solved (AC)
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays
class Solution {
public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> mapTarget;
    unordered_map<int, int> mapArr;
    
    for(int i = 0; i < target.size(); i++) {
      mapTarget[target[i]]++;
      mapArr[arr[i]]++;
    }
    
    return mapTarget == mapArr;
  }
};
/*
12345
53124 -> 135 24 -> 1 253 4 -> 12 35 4 -> 123 45

*/