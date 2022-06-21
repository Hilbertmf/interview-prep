// no solution yet (wrong answer)
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
class Solution {
public:
    int dfs(int node, vector<vector<int>>& graph, unordered_set<int>& visited, int path) {
        path++;

        for(auto &neighbor : graph[node]) {
            if(visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                dfs(node, graph, visited, path);
            }
        }

        if(visited.size() < graph.size())
            path++;
        return path;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_set<int> visited;
        visited.reserve(graph.size());
        int path = INF;
        path = min(path, dfs(0, graph, visited, 0));

        return path;
    }
};