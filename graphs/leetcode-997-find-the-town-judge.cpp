// accepted
// https://leetcode.com/problems/find-the-town-judge
// time: O(n)
// space: O(n)
class Solution {
public:    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> parents(n + 1);
        vector<unordered_set<int>> children(n + 1);

        int judge = -1;
        int numJudges = 0;
        for(auto &edge : trust) {
            children[edge[0]].insert(edge[1]);
            parents[edge[1]].insert(edge[0]);
        }

        for(int i = 1; i <= n; ++i) {
            if(children[i].size() != 0)
                continue;
            if(parents[i].size() == n - 1) {
                numJudges++;
                judge = i;
            }
        }
        
        if(numJudges == 1)
            return judge;
        else
            return -1;
    }
};