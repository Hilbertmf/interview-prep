class Solution{
    public:
    bool dfsHelper(int source, int destination, vector<vector<int>>& graph, vector<bool>& visited) {
        if(source == destination) return true;

        if(!visited[source]) {
            visited[source] = true;

            for(int col = 0; col < graph[source].size(); ++col) {
                if(col != source && graph[source][col] && dfsHelper(col, destination, graph, visited))
                    return true;
            }
        }
        return false;
    }

    bool hasPathDfs(int source, int destination, vector<vector<int>>& graph, vector<bool>& visited) {
        fill(visited.begin(), visited.end(), false);
        return dfsHelper(source, destination, graph, visited);
    }

    bool bfsHelper(int source, int destination, vector<vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if(curr == destination)  {
                return true;
            }
            if(!visited[curr]) {
                visited[curr] = true;

                for(int col = 0; col < graph[curr].size(); ++col) {
                    if(graph[curr][col] == 1 && col != curr)
                        q.push(col);
                }
            }
        }

        return false;
    }

    bool hasPathBfs(int source, int destination, vector<vector<int>>& graph, vector<bool>& visited) {
        fill(visited.begin(), visited.end(), false);
        return bfsHelper(source, destination, graph, visited);
    }

    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
        vector<vector<int>> transitiveGraph = graph;

        vector<bool> visited(N);

        for(int i = 0; i < transitiveGraph.size(); ++i) {
            for(int j = 0; j < transitiveGraph[i].size(); ++j) {
                // bool hasLink = hasPathBfs(i, j, transitiveGraph, visited);
                bool hasLink = hasPathDfs(i, j, transitiveGraph, visited);
                if(transitiveGraph[i][j] == 0 && hasLink)
                    transitiveGraph[i][j] = 1;
            }
        }

        return transitiveGraph;
    }
};
