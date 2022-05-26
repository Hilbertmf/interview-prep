// Linear solution using 2 pointers
// time: O(n)
// space: O(n)
#define INF 1e9
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size());

        int posIdx = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();// positive index
        int negIdx = posIdx - 1;// negative index
        
        while(negIdx >= 0 || posIdx < nums.size()) {
            int negative = INF, positive = INF;
            if(negIdx >= 0)
                negative = nums[negIdx] * nums[negIdx];
            if(posIdx < nums.size())
                positive = nums[posIdx] * nums[posIdx];
            
            res.push_back(min(abs(negative), positive));
            
            if(abs(negative) < positive)
                --negIdx;
            else
                ++posIdx;
        }
        return res;
    }
};