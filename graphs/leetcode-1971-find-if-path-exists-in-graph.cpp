// time: O(n)
// space: O(n)
class Solution {
public:
    bool bfs(int source, int destination, vector<list<int>>& adjList, vector<bool>& visited) {
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr == destination) return true;
            if(!visited[curr]) {
                visited[curr] = true;
                for(const auto &neighbor : adjList[curr]) {
                    q.push(neighbor);
                }
            }

        }

        return false;
    }
    
    bool dfs(int source, int destination, vector<list<int>>& adjList, vector<bool>& visited) {
        if(source == destination)
            return true;
        
        if(!visited[source]) {
            visited[source] = true;
            
            for(auto &neighbor : adjList[source]) {
                if(dfs(neighbor, destination, adjList, visited))
                    return true;
            }
            
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n);
        vector<list<int>> adjList(n);

        for(const auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return bfs(source, destination, adjList, visited);
    }
};