// accepted
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
// all children of 0 need to be reordered
// check for their parents as well, their children also needs to be reordered
// do that recursively
// time: O(V+E)
// space: O(V+E)
class Solution {
public:
    void dfs(int node, vector<list<int>>& graph, vector<list<int>>& parents,
    vector<bool>& visited, int& count, bool isParent) {
        if(!isParent) {
            count++;
        }

        for(auto &parent : parents[node]) {
            if(!visited[parent]) {
                visited[parent] = true;
                dfs(parent, graph, parents, visited, count, true);
            }
        }
        
        for(auto &child : graph[node]) {
            if(!visited[child]) {
                visited[child] = true;
                dfs(child, graph, parents, visited, count, false);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<list<int>> graph(n);
        vector<list<int>> parents(n);
        vector<bool> visited(n);
        // construct graph
        for(auto &connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            parents[connection[1]].push_back(connection[0]);
        }

        int count = 0;
        visited[0] = true;
        dfs(0, graph, parents, visited, count, true);
        
        return count;
    }
};