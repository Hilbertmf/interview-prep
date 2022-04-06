// // solved (AC)
// https://leetcode.com/problems/kth-missing-positive-number/
class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int nums = 1;
    int kthMissingNum = 0;
    
    for(int i = 0;
        i < arr.size() && kthMissingNum < k;
        i++, nums++) {
      while(nums < arr[i] && kthMissingNum < k) {
        kthMissingNum++;
        nums++;
      }
    }
    
    if(kthMissingNum < k)
      nums += (k - kthMissingNum) + 1;
    
    return nums-2;
  }
};

/*
k = 
kthMissingNum = 
nums = 
arr[i] = 

time: O(k)
space: O(1)
*/