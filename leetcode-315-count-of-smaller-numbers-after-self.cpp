#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<
long long, // key type
null_type, // mapped-policy
less_equal<long long>, // key comparison function
rb_tree_tag, // underlying data structure
tree_order_statistics_node_update>
ordered_multiset;


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> smaller(nums.size());
        ordered_multiset mySet;
        int count = 0;
        for(int i = nums.size() - 1; i >= 0; --i) {
            mySet.insert(nums[i]);
            count = mySet.order_of_key(nums[i]);
            smaller[i] = count;
        }
        
        return smaller;
    }
};