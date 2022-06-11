#include <bits/stdc++.h>
using namespace std;

// Traverse all islands in grid2
// For each island store its cells in a vector of pairs
// For each vector: if all cells are 1s in grid1: answer++

//  time: O(V*V)
//  space: O(V*V)
class Solution {
public:
    vector<int> rowDir{1, -1, 0, 0};
    vector<int> colDir{0, 0, 1, -1};
    
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() &&
        grid[row][col];
    }
    
    void traverse(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited,
    vector<pair<int, int>>& island) {
        island.push_back({row, col});

        for(int i = 0; i < 4; ++i) {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];

            if(!valid(nextRow, nextCol, grid))
                continue;
            if(!visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                traverse(nextRow, nextCol, grid, visited, island);
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size(), cols = grid1[0].size();
        vector<vector<pair<int, int>>> islands;
        islands.reserve(rows * cols - 1);
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int numSubIslands = 0;
        int count = -1;

        // traverse grid2 islands
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(!visited[r][c] && grid2[r][c]) {
                    visited[r][c] = true;
                    ++count;
                    islands.push_back(vector<pair<int, int>>());
                    traverse(r, c, grid2, visited, islands[count]);
                    
                }
            }
        }

        for(const auto &island : islands) {
            bool isSubIsland = true;
            for(const auto &p : island) {
                if(grid1[p.first][p.second] == 0) {
                    isSubIsland = false;
                    break;
                }
            }

            if(isSubIsland)
                numSubIslands++;
        }

        return numSubIslands;
    }
};
