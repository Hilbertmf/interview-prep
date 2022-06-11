#include <bits/stdc++.h>
using namespace std;

vector<int> rowDir{1, -1, 0, 0};
vector<int> colDir{0, 0, 1, -1};

class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        bool hasIsland = true;

        for(int i = 0; i < 4; ++i) {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];

            if(nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size())
                continue;
            if(grid[nextRow][nextCol] == 1)
                continue;
            if(!visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                hasIsland = hasIsland & dfs(nextRow, nextCol, grid, visited);
            }
        }
        if(row == 0 || col == 0 || row == grid.size() - 1 || col == grid[0].size() - 1)
            hasIsland = false;

        return hasIsland;
    }

    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int closedIslands = 0;

        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(visited[r][c] || grid[r][c] == 1)
                    continue;
                visited[r][c] = true;
                closedIslands += dfs(r, c, grid, visited);
                
            }
        }

        return closedIslands;
    }
};
