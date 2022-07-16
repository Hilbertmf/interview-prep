// accepted
// https://leetcode.com/problems/as-far-from-land-as-possible/
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
class Solution {
public:
    vector<int> dr{1, -1, 0, 0};
    vector<int> dc{0, 0, 1, -1};

    struct state{
        int row;
        int col;
        int dist;
    };
    
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }

    void multisourceBfs(vector<pair<int, int>>& land, vector<vector<int>>& grid,
    vector<vector<int>>& dists) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        queue<state> qu;
        for(auto &[r, c] : land) {
            qu.push((state){r, c, 0});
            dists[r][c] = 0;
            visited[r][c] = true;
        }

        while (!qu.empty()) {
            int r = qu.front().row;
            int c = qu.front().col;
            int dist = qu.front().dist;
            qu.pop();

            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(!valid(nr, nc, grid) || visited[nr][nc]) continue;
                
                visited[nr][nc] = true;
                dists[nr][nc] = min(dists[nr][nc], dist + 1);
                qu.push((state){nr, nc, dists[nr][nc]});
            }
        }
    }

    int maxDistance(vector<vector<int>>& grid) {
        int numLandCells = 0, numWaterCells = 0;
        for(int i = 0; i < grid.size(); ++i) {
            numLandCells += count(grid[i].begin(), grid[i].end(), 1);
            numWaterCells += count(grid[i].begin(), grid[i].end(), 0);
        }
        if(numWaterCells == 0 || numLandCells == 0)
            return -1;
        
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> distToLand(rows, vector<int>(cols, INF));
        vector<pair<int, int>> landCells;
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == 1) landCells.push_back({r, c});
            }
        }

        multisourceBfs(landCells, grid, distToLand);
        int dist = 0;
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                dist = max(dist, distToLand[r][c]);
            }
        }

        return dist;
    }
};

