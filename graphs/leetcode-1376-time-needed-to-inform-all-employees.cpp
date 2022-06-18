// accepted
// https://leetcode.com/problems/time-needed-to-inform-all-employees
// construct a tree, then get depth
class Solution {
public:
    void constructTree(vector<list<int>>& tree, vector<int>& manager) {
        int n = tree.size();

        for(int i = 0; i < n; ++i) {
            if(manager[i] == -1)
                continue;

            tree[manager[i]].push_back(i);
        }        
    }

    int informEmployees(int root, vector<list<int>>& tree, vector<int>& informTime) {
        int time = 0;
        for(const auto &neighbor : tree[root]) {
            time = max(time, informTime[root] + informEmployees(neighbor, tree, informTime));
        }

        return time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<list<int>> tree(n);

        constructTree(tree, manager);
        
        return informEmployees(headID, tree, informTime);

    }
};
