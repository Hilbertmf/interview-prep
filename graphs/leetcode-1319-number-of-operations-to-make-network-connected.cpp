// accepted
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    void traverseComponents(int vertex, vector<list<int>>& graph, vector<bool>& visited) {
        for(auto neighbor : graph[vertex]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                traverseComponents(neighbor, graph, visited);
            }
        }
    }

    void detectedCycles(int vertex, int parent, vector<list<int>>& graph,
    vector<bool>& visited, int& cycles) {
        for(auto neighbor : graph[vertex]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                detectedCycles(neighbor, vertex, graph, visited, cycles);
            }
            // cycle:
            else if(neighbor != parent) { // already visited, not parent but a neighbor
                cycles++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<list<int>> graph(n);
        for(int i = 0; i < connections.size(); ++i) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> visited(n);
        int numComponents = 0;
        for(int v = 0; v < graph.size(); ++v) {
            if(!visited[v]) {
                visited[v] = true;
                traverseComponents(v, graph, visited);
                numComponents++;
            }
        }

        fill(visited.begin(), visited.end(), false);
        int cycles = 0;
        for(int v = 0; v < graph.size(); ++v) {
            if(!visited[v]) {
                visited[v] = true;
                detectedCycles(v, -1, graph, visited, cycles);
            }
        }

        cycles /= 2; // we're counting each cycle twice

        if(numComponents - 1 > cycles)
            return -1;
        else
            return numComponents - 1;
    }
};
