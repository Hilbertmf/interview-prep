// time: O(V + E)
// space: O(V + E)
vector<int> rowDirections{1, -1, 0, 0};
vector<int> colDirections{0, 0, 1, -1};
class Solution {
public:
    
    bool hasIsland(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(grid[row][col] == '0') return false;

        bool hasUnvisitedIsland = grid[row][col] == '1';

        for(int i = 0; i < 4; ++i) {
            int nextRow = row + rowDirections[i];
            int nextCol = col + colDirections[i];
            
            if(nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size())
                continue;
            if(grid[nextRow][nextCol] != '1')
                continue;
            
            if(!visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                hasIsland(nextRow, nextCol, grid, visited);
            }
        }
        return hasUnvisitedIsland;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int islands = 0;

        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(!visited[r][c]) {
                    visited[r][c] = true;
                    if(hasIsland(r, c, grid, visited))
                        islands++;
                }
            }
        }
        return islands;
    }
};
