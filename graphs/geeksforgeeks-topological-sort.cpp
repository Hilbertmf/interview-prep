// accepted
// https://practice.geeksforgeeks.org/problems/topological-sort/1/
class Solution {
    public:
    void getTopologicalSort(int curr, int V, vector<int> adj[], vector<bool>& visited,
    vector<int>& order) {

        for(auto vertex : adj[curr]) {
            if(!visited[vertex]) {
                visited[vertex] = true;
                getTopologicalSort(vertex, V, adj, visited, order);
            }
        }

        order.push_back(curr);
    }

    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        vector<int> order;
        order.reserve(V);

        for(int i = 0; i < visited.size(); ++i) {
            if(!visited[i]) {
                visited[i] = true;
                getTopologicalSort(i, V, adj, visited, order);
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
