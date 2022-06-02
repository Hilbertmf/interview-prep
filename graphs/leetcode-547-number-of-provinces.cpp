class Solution {
public:
    void visitProvince(int source, vector<vector<int>>& graph, vector<bool>& visited) {
        if(!visited[source]) {
            visited[source] = true;
            for(int col = 0; col < graph[source].size(); ++col) {
                if(col != source && graph[source][col])
                    visitProvince(col, graph, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int numProvinces = 0;
        
        for(int vertex = 0; vertex < isConnected.size(); ++vertex) {
            if(!visited[vertex]) numProvinces++;
            visitProvince(vertex, isConnected, visited);
        }
        
        return numProvinces;
    }
};