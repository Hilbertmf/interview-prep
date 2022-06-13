// accepted
// https://leetcode.com/problems/shortest-path-in-binary-matrix
class Solution {
public:
    vector<int> rowDir{1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> colDir{0, 0, 1, -1, 1, -1, -1, 1};

    struct state {
        int row;
        int col;
        int dist;
    };
    
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() &&
        grid[row][col] == 0;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        queue<state> q;
        if(grid[0][0] == 0) {
            q.push((state){0, 0, 1});
            visited[0][0] = true;
        }
        
        while (!q.empty()) {
            int row = q.front().row;
            int col = q.front().col;
            int dist = q.front().dist;
            q.pop();

            if(row == grid.size() - 1 && col == grid[0].size() - 1 &&
            grid[row][col] == 0)
                return dist;

            for(int i = 0; i < 8; ++i) {
                int nextRow = row + rowDir[i];
                int nextCol = col + colDir[i];

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

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        return bfs(grid, visited);
    }
};
