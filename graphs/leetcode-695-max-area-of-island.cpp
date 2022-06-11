#include <bits/stdc++.h>
using namespace std;

vector<int> rowDir{1, -1, 0, 0};
vector<int> colDir{0, 0, 1, -1};

class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if(grid[row][col] == 0) return 0;

        int area = 0;
        for(int i = 0; i < 4; ++i) {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];

            if(nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size())
                continue;
            if(grid[nextRow][nextCol] == 0)
                continue;
            if(!visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                area += dfs(nextRow, nextCol, grid, visited);
            }
        }
        return area + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int maxArea = 0;

        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(!visited[r][c]) {
                    visited[r][c] = true;
                    maxArea = max(maxArea, dfs(r, c, grid, visited));
                }
            }
        }

        return maxArea;
    }
};

/*
[
[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]
]
*/