// accepted
// https://leetcode.com/problems/shortest-bridge/
// Solution using DFS to get all borders of one island
// then BFS w/ mulitple sources starting from the borders
// to get the minimum distance to the other island

// Time: O(V+E)
// Space: O(V+E)
class Solution {
public:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int, int> & v) const {
            return v.first*31+v.second;
        }
    };

    struct state {
        int row;
        int col;
        int dist;
    };

    vector<int> dr{1, -1, 0, 0};
    vector<int> dc{0, 0, 1, -1};    

    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited,
    unordered_set<pair<int, int>, pair_hash>& border) {
        
        for(int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(!valid(nr, nc, grid)) {
                border.insert({row, col});
                continue;
            }
            if(grid[nr][nc] == 0)
                border.insert({row, col});
            else if(!visited[nr][nc]) {
                visited[nr][nc] = true;
                dfs(nr, nc, grid, visited, border);
            }
        }
    }

    int multiSourceBfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
    unordered_set<pair<int, int>, pair_hash>& border, int& bridge) {
        queue<state> q;
        for(const auto &nodePair : border) {
            q.push((state){nodePair.first, nodePair.second, 0});
            visited[nodePair.first][nodePair.second] = false;
        }

        while(!q.empty()) {
            int r = q.front().row;
            int c = q.front().col;
            int dist = q.front().dist;
            q.pop();

            if(visited[r][c])
                continue;
            if(!visited[r][c] && border.find({r, c}) == border.end() && grid[r][c] == 1) {
                return dist;
            }

            visited[r][c] = true;

            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(!valid(nr, nc, grid))
                    continue;
                if(!visited[nr][nc]) {
                    q.push((state){nr, nc, dist + 1});
                }
            }
        }

        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0.].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        unordered_set<pair<int, int>, pair_hash> border;
        bool found = false;

        for(int r = 0; r < rows && !found; ++r) {
            for(int c = 0; c < cols && !found; ++c) {
                if(grid[r][c] == 1 && !visited[r][c]) {
                    visited[r][c] = true;
                    dfs(r, c, grid, visited, border);
                    found = true;
                }
            }
        }

        int bridge = multiSourceBfs(grid, visited, border, bridge);

        return bridge - 1;
    }
};
