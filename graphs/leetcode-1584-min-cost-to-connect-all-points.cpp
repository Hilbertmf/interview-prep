#include <bits/stdc++.h>
using namespace std;

// Prim's minimum spanning tree algorithm
// time: O(E*log(E))
// space: O(V + E)
class Solution {
public:
    int minimumSpanningTreeCost(int start, vector<vector<pair<int, int>>>& graph) {
        vector<bool> visited(graph.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        int totalCost = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(visited[node]) continue;
            visited[node] = true;
            totalCost += cost;

            for(auto &[neighbor, weight] : graph[node]) {
                pq.push({weight, neighbor});
            }
        }
        
        return totalCost;
    }

    int getDist(vector<int>& p1, vector<int>& p2) {
        int x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1];
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> graph(points.size());
        for(int i = 0; i < points.size(); ++i) {
            for(int j = 0; j < points.size(); ++j) {
                if(i == j) continue;
                graph[i].push_back({j, getDist(points[i], points[j])});
            }
        }

        return minimumSpanningTreeCost(0, graph);
    }
};