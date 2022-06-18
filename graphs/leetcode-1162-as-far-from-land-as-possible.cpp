#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
class Solution {
public:
    vector<int> dr{1, -1, 0, 0};
    vector<int> dc{0, 0, 1, -1};

    int getDist(int row1, int col1, int row2, int col2) {
        return abs(row1 - row2) + abs(col1 - col2);
    }
    
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }
    
    void dfs(int row, int col, int rowPar, int colPar, vector<vector<int>>& grid, vector<vector<bool>>& visited,
    vector<vector<int>>& distToLand) {
        if(rowPar != -1 && colPar != -1) {
            int dist = getDist(row, col, rowPar, colPar);
            distToLand[row][col] = min(distToLand[row][col], distToLand[rowPar][colPar] + dist);
        }
            

        for(int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(!valid(nr, nc, grid))
                continue;
            if(grid[nr][nc] == 1)
                distToLand[row][col] = min(distToLand[row][col], getDist(row, col, nr, nc));
            
            int dist = getDist(row, col, nr, nc);
            distToLand[row][col] = min(distToLand[row][col], distToLand[nr][nc] + dist);
            if(!visited[nr][nc] && grid[nr][nc] == 0) {
                visited[nr][nc] = true;
                dfs(nr, nc, row, col, grid, visited, distToLand);
                distToLand[row][col] = min(distToLand[row][col], distToLand[nr][nc] + dist);
            }

        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> distToLand(grid.size(), vector<int>(grid[0].size(), INF));
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int num0s = 0, num1s = 0;
        // populate distToLand on land
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 1) {
                    distToLand[r][c] = 0;
                    num1s++;
                }
                else
                    num0s++;
            }
        }

        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 0 && !visited[r][c]) {
                    visited[r][c] = true;
                    dfs(r, c, -1, -1, grid, visited, distToLand);
                }
            }
        }
        
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                visited[r][c] = false;
            }
        }

        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 0 && !visited[r][c]) {
                    visited[r][c] = true;
                    dfs(r, c, -1, -1, grid, visited, distToLand);
                }
            }
        }

        int dist = 0;
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 0) {
                    dist = max(dist, distToLand[r][c]);
                }
            }
        }

        if(dist == INF || num0s == 0 || num1s == 0)
            dist = -1;
            
        return dist;
    }
};
