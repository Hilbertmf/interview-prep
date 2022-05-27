// https://leetcode.com/problems/flatten-nested-list-iterator
// accepted
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
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
class NestedIterator {
public:
    // iterative solution
    // time: O(n)
    // space: O(n)
    vector<int> list;
    vector<int>::iterator it;

    void dfsIterative(NestedInteger& item) {
        stack<NestedInteger> myStack;
        myStack.push(item);

        while(!myStack.empty()) {
            auto top = myStack.top();
            myStack.pop();
            if(top.isInteger()) {
                list.push_back(top.getInteger());
            }
            else {
                int size = top.getList().size();
                for(int i = size - 1; i >= 0; --i) {
                    myStack.push(top.getList()[i]);
                }
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto &item : nestedList)
            dfsIterative(item);

        it = list.begin();
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != list.end();
    }
};

// recursive solution
// time: O(n)
// space: O(n)
class NestedIterator {
public:
    vector<int> list;
    vector<int>::iterator it;

    void dfs(NestedInteger& item) {
        if(item.isInteger()) { // integer
            list.push_back(item.getInteger());
        }
        else {
            for(auto& currItem : currList.getList()) {
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
        return *it++;
    }

    bool hasNext() {
        return it != list.end();
    }
};