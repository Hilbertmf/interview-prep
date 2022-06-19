// accepted
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// get topological sort
// then traverse graph using topological sort 
class Solution {
public:
    void topsort(int node, vector<list<int>>& graph, vector<bool>& visited,
    vector<int>& order) {

        for(auto &neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                topsort(neighbor, graph, visited, order);
            }
        }
        order.push_back(node);
    }

    void traverse(int node, vector<list<int>>& graph, vector<bool>& visited) {
        
        for(auto &neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                traverse(neighbor, graph, visited);
            }
        }        
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<list<int>> graph(n);
        vector<bool> visited(n);
        vector<int> answer;

        for(auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> order;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                topsort(i, graph, visited, order);
            }
        }
        reverse(order.begin(), order.end());

        fill(visited.begin(), visited.end(), false);

        for(auto &node : order) {
            if(!visited[node]) {
                visited[node] = true;
                answer.push_back(node);
                traverse(node, graph, visited);
            }
        }

        return answer;
    }
};