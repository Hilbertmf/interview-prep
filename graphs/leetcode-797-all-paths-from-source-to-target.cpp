// accepted
// https://leetcode.com/problems/all-paths-from-source-to-target
// time: O(V*E) adj list
// space: O(V*E) adj list
class Solution {
public:
    void dfs(int node, int target, vector<vector<int>>& graph, vector<int> path,
    vector<vector<int>>& paths) {
        path.push_back(node);
        if(node == target) {
            paths.push_back(path);
        }

        for(auto &neighbor : graph[node]) {
            dfs(neighbor, target, graph, path, paths);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        dfs(0, graph.size() - 1, graph, vector<int>{}, paths);
        return paths;
    }
};