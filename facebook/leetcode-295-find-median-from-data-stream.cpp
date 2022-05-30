// https://leetcode.com/problems/find-median-from-data-stream
// time: O(nlogn)
// space: O(n)
class MedianFinder {
public:
    multiset<int> leftSet;
    multiset<int> rightSet;

    MedianFinder() {
        leftSet = multiset<int>();
        rightSet = multiset<int>();
    }
    
    void addNum(int num) {
        if(!leftSet.empty() && num < *prev(leftSet.end()) ) { // belongs to leftSet
            leftSet.insert(num);
            if(leftSet.size() > rightSet.size() + 1) { // diff exceeds 1
                rightSet.insert(*prev(leftSet.end()));
                leftSet.erase(prev(leftSet.end()));
            }
        }
        else {
            rightSet.insert(num);
            if(rightSet.size() > leftSet.size() + 1) { // diff exceeds 1
                leftSet.insert(*rightSet.begin());
                rightSet.erase(rightSet.begin());
            }
        }
    }
    
    double findMedian() {
        if((leftSet.size() + rightSet.size()) % 2 == 1) {
            if(leftSet.size() > rightSet.size())
                return *prev(leftSet.end());
            else
                return *rightSet.begin();
        }
        else {
            return (*prev(leftSet.end()) + *rightSet.begin()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */