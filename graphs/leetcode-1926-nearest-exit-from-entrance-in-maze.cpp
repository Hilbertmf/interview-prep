// accepted
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

// solution using bfs to get minimum distance
// time: O(V+E)
// time: O(V+E)
class Solution {
public:
    struct state {
        int row;
        int col;
        int dist;
    };

    vector<int> dr{1, -1, 0, 0};
    vector<int> dc{0, 0, 1, -1};

    bool valid(int row, int col, vector<vector<char>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() &&
        grid[row][col] == '.';
    }
    bool exit(int row, int col, vector<vector<char>>& grid, vector<int>& entrance) {
        return grid[row][col] == '.' && (row != entrance[0] || col != entrance[1]) && 
        (row == 0 || row == grid.size() - 1 || col == 0 || col == grid[0].size() - 1);
    }
    
    int bfs(vector<int>& entrance, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<state> q;
        q.push((state){entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;

        while(!q.empty()) {
            int row = q.front().row;
            int col = q.front().col;
            int dist = q.front().dist;
            q.pop();

            if(exit(row, col, grid, entrance)) {
                return dist;
            }

            for(int i = 0; i < 4; ++i) {
                int nextRow = row + dr[i];
                int nextCol = col + dc[i];

                if(!valid(nextRow, nextCol, grid))
                    continue;
                if(!visited[nextRow][nextCol]) {
                    visited[nextRow][nextCol] = true;
                    q.push((state){nextRow, nextCol, dist + 1});
                }
            }
        }

        return -1;
    }

    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        
        return bfs(entrance, grid, visited);
    }
};