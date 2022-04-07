// solved (AC)
// https://leetcode.com/problems/merge-intervals/
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals;
    std::sort(intervals.begin(), intervals.end());
    
    mergedIntervals.push_back(intervals[0]);
    vector<int> merged = intervals[0], curr;
    
    for(int i = 1; i < intervals.size(); i++) {
      curr = intervals[i];
      if(merged[1] >= curr[0]) {
        mergedIntervals[mergedIntervals.size()-1][1] = max(curr[1], merged[1]);
        merged[1] = max(curr[1], merged[1]);
      }
      else {
        mergedIntervals.push_back(curr);
        merged = intervals[i];
      }
    }
    
    return mergedIntervals;
  }
};
/*
-> sort vector
-> iterate over vector
-> if curr->second >= next->first: overlap()
-> else: push(next); curr = next

[[1,2],[1,3],[2,6],[8,10],[15,18]]
                           |
[[1,6], [8,10], [15,18]]

time:O(nlogn)
space:O(n)
edge cases:
intervals.size == 1
*/