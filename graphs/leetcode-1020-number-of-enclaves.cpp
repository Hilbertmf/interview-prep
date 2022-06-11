//  time: O(V*E)
//  space: O(V*E)
// create external node that links to matrix edges
// go from external and visit all neighbors w/ 1
// count remainder 1s
class Solution {
public:
    vector<int> rowDir{1, -1, 0, 0};
    vector<int> colDir{0, 0, 1, -1};

    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() &&
        grid[row][col];
    }

    void traverse(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {

        for(int i = 0; i < 4; ++i) {
            int nxtRow = row + rowDir[i];
            int nxtCol = col + colDir[i];

            if(!valid(nxtRow, nxtCol, grid))
                continue;
            if(!visited[nxtRow][nxtCol]) {
                visited[nxtRow][nxtCol] = true;
                traverse(nxtRow, nxtCol, grid, visited);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));

        vector<pair<int, int>> externalNeighbors;
        for(int r = 0; r < rows; ++r) {
            if(r == 0 || r == rows - 1) {
                for(int c = 0; c < cols; ++c) {
                    if(grid[r][c])
                        externalNeighbors.push_back({r, c});
                }
            }
            else {
                if(grid[r][0])
                    externalNeighbors.push_back({r, 0});
                if(grid[r][cols - 1])
                    externalNeighbors.push_back({r, cols - 1});
            }
        }

        for(auto &p : externalNeighbors) {
            if(!visited[p.first][p.second]) {
                visited[p.first][p.second] = true;
                traverse(p.first, p.second, grid, visited);
            }
        }

        int enclaves = 0;
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(!visited[r][c] && grid[r][c])
                    enclaves++;
            }
        }

        return enclaves;
    }
};
