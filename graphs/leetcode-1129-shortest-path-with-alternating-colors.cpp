#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
class Solution {
public:
    struct state{
        int node;
        char color;
        int dist;
    };
    
    void bfs(int source, vector<int>& dists, vector<list<pair<int, char>>>& graph,
    vector<int>& parents, vector<unordered_set<string>>& visited) {
        queue<state> q;
        q.push((state){source, ' ', 0});
        // mark source as visited
        for(int i = 0; i < parents[source]; ++i) {
            visited[source].insert(to_string(i));
        }
        dists[source] = 0;

        while (!q.empty()) {
            int curr = q.front().node;
            char color = q.front().color;
            int dist = q.front().dist;
            q.pop();


            for(auto &edgePair : graph[curr]) {
                int neighbor = edgePair.first;
                char neighborColor = edgePair.second;

                if(color == neighborColor ||
                visited[neighbor].size() >= parents[neighbor])
                    continue;

                visited[neighbor].insert(to_string(curr) + to_string(neighborColor));
                dists[neighbor] = min(dists[neighbor], dist + 1);
                q.push((state){neighbor, neighborColor, dist + 1});
                
            }
        }
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
    vector<vector<int>>& blueEdges) {
        vector<list<pair<int, char>>> graph(n);
        vector<int> parents(n);
        vector<int> dists(n, INF);
        vector<unordered_set<string>> visited(n);

        for(auto &edge : redEdges) {
            graph[edge[0]].push_back({edge[1], 'r'});
            parents[edge[1]]++;
        }

        for(auto &edge : blueEdges) {
            graph[edge[0]].push_back({edge[1], 'b'});
            parents[edge[1]]++;
        }

        for(int i = 0; i < n; ++i) {
            visited[i].reserve(parents[i]);
        }

        bfs(0, dists, graph, parents, visited);
        replace(dists.begin(), dists.end(), (int)INF, -1);
        return dists;
    }
};