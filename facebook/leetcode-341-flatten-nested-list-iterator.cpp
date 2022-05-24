/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// recursive solution
// time: O(num of integers)
// space: O(num of integers + depth of list)
class NestedIterator {
public:
    vector<int> list;
    vector<int>::iterator it;
    
    void dfs(NestedInteger& item) {
        if(item.isInteger()) { // integer
            list.push_back(item.getInteger());
        }
        else {
            vector<NestedInteger> currList = item.getList();
            for(auto& currItem : currList) {
                dfs(currItem); 
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto& item : nestedList) {
            dfs(item);
        }
        it = list.begin();
    }
    
    int next() {
        int res = *it;
        ++it;
        return res;
    }
    
    bool hasNext() {
        return it != list.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */