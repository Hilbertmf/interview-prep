// accepted
// https://leetcode.com/problems/possible-bipartition/
// solution coloring the graph w/ 0 and 1
class Solution {
public:
    void dfs(int node, vector<list<int>>& graph, vector<int>& color, int group) {
        group ^= 1;

        for(auto &neighbor : graph[node]) {
            if(color[neighbor] == -1) {
                color[neighbor] = group;
                dfs(neighbor, graph, color, group);
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<list<int>> graph(n+1);
        vector<int> color(n+1, -1);
        for(auto &relation : dislikes) {
            graph[relation[0]].push_back(relation[1]);
            graph[relation[1]].push_back(relation[0]);
        }

        for(int i = 1; i <= n; ++i) {
            if(color[i] == -1) {
                color[i] = 1;
                dfs(i, graph, color, 1);
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(auto &neighbor : graph[i]) {
                if(color[i] == color[neighbor]) // same group and dislike each other
                    return false;
            }
        }

        return true;
    }
};