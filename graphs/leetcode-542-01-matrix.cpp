// multisource bfs from 0s
// time: O(V²)
// space: O(V²)
class Solution {
public:
    vector<int> rowDir{1, -1, 0, 0};
    vector<int> colDir{0, 0, 1, -1};
    
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }

    void multiSourcedBfs(vector<pair<int, int>>& sources, vector<vector<int>>& grid,
    vector<vector<bool>>& visited, vector<vector<int>>& dist) {
        queue<pair<int, int>> q;
        for(const auto &p : sources) {
            q.push({p.first, p.second});
            visited[p.first][p.second] = true;
        }

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int nr = r + rowDir[i];
                int nc = c + colDir[i];

                if(!valid(nr, nc, grid))
                    continue;
                if(!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                    dist[nr][nc] = dist[r][c] + 1;
                }
            }
        }
    }
    

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols));
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        vector<pair<int, int>> sources;

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(!grid[r][c])
                    sources.push_back({r, c});
            }
        }

        multiSourcedBfs(sources, grid, visited, dist);
        return dist;
    }
};
