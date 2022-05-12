// accepted
// https://leetcode.com/problems/subarray-sum-equals-k/submissions/
class Solution {
public:
    // time: O(n)
    // space: O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFrequencies;
        vector<int> prefixSum(nums.size());
        int count = 0;
        int acc = 0;

        for(int i = 0; i < nums.size(); ++i) {
            acc += nums[i];
            prefixSum[i] += acc;
        }

        for(const auto &sum : prefixSum) {
            if(sum == k) count++;
            count += sumFrequencies[sum - k];
            sumFrequencies[sum]++;
        }

        return count;
    }

};