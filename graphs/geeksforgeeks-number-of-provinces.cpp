#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // dfs-like function to mark all connected segment as visited
    // and returns false if its already been marked
    bool isNewProvince(int source, vector<vector<int>>& graph, vector<bool>& visited) {
        if(!visited[source]) {
            visited[source] = true;
            for(int col = 0; col < graph[source].size(); ++col) {
                if(col != source && graph[source][col] == 1)
                    isNewProvince(col, graph, visited);
            }

            return true;
        }
        else {
            return false;
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        int count = 0;
        vector<bool> visited(V);

        for(int vertex = 0; vertex < V; ++vertex) {
            if(isNewProvince(vertex, adj, visited))
                count++;
        }
        
        return count;
    }
};