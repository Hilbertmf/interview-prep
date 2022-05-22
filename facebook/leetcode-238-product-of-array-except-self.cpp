// https://leetcode.com/problems/leetcode-238-product-of-array-except-self/
// time: O(n)
// space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int prefixProd = nums[0];
        int suffixProd = nums[nums.size() - 1];

        for(int i = 1; i < nums.size(); ++i) {
            result[i] *= prefixProd;
            prefixProd *= nums[i];
        }

        for(int i = nums.size() - 2; i >= 0 ; --i) {
            result[i] *= suffixProd;
            suffixProd *= nums[i];
        }

        return result;
    }
};