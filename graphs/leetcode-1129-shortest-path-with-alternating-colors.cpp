// accepted
// https://leetcode.com/problems/shortest-path-with-alternating-colors/
// time: O(V + E)
// space: O(V)
// 2d graph, one dimension for each color of edges
// one visited arrays for each color
// perform bfs starting from blue and then from red
class Solution {
public:
    #define INF (int)1e8
    struct state {
        int node;
        int color;
        int dist;
    };

    void bfs(int node, vector<vector<list<int>>>& graph, vector<vector<bool>>& visited,
    vector<int>& answer, int color) {
        queue<state> qu;
        qu.push((state){node, color, 0});

        while (!qu.empty()) {
            int v = qu.front().node;
            int c = qu.front().color;
            int dist = qu.front().dist;
            qu.pop();

            for(auto &neighbor : graph[c][v]) {
                if(visited[c][neighbor]) continue;
                visited[c][neighbor] = true;
                answer[neighbor] = min(answer[neighbor], dist + 1);
                qu.push((state){neighbor, c ^ 1, dist + 1});
            }
        }
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> answer(n, INF);
        vector<vector<list<int>>> graph(2, vector<list<int>>(n));
        vector<vector<bool>> visited(2, vector<bool>(n));

        for(auto &edge : redEdges) {
            graph[0][edge[0]].push_back(edge[1]);
        }

        for(auto &edge : blueEdges) {
            graph[1][edge[0]].push_back(edge[1]);
        }

        answer[0] = 0;
        for(int color = 0; color < 2; ++color) {        
            if(color > 0)
                for(int j = 0; j < 2; ++j)
                    fill(visited[j].begin(), visited[j].end(), false);
                
            visited[color][0] = true;
            bfs(0, graph, visited, answer, color);
        }

        replace(answer.begin(), answer.end(), INF, -1);

        return answer;
    }
};
