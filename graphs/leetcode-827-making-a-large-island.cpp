// accepted
// https://leetcode.com/problems/making-a-large-island/
// paint the cells w/ ther island index
// then iterate over the matrix looking for
// maximum possible area between islands
// time: O(rows * cols)
// space: O(rows * cols)
class Solution {
public:
    vector<int> rowDir{1, -1, 0, 0};
    vector<int> colDir{0, 0, 1, -1};
    
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }

    int paint(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited,
    int count) {
        int area = 0;
        for(int i = 0; i < 4; ++i) {
            int nxtRow = row + rowDir[i];
            int nxtCol = col + colDir[i];

            if(!valid(nxtRow, nxtCol, grid))
                continue;
            if(visited[nxtRow][nxtCol] || grid[nxtRow][nxtCol] == 0)
                continue;
            visited[nxtRow][nxtCol] = true;
            area += paint(nxtRow, nxtCol, grid, visited, count);
        }

        grid[row][col] = count;
        return area + 1;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        vector<int> islands(2);
        int maxArea = 0;
        int count = 2;

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(visited[r][c] || grid[r][c] == 0)
                    continue;
                visited[r][c] = true;
                int area = paint(r, c, grid, visited, count);
                islands.push_back(area);
                count++;
            }
        }

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == 0) {
                    int sum = 0;
                    set<int> adjIslands;
                    for(int i = 0; i < 4; ++i) {
                        int nextRow = r + rowDir[i];
                        int nextCol = c + colDir[i];
                        if(!valid(nextRow, nextCol, grid))
                            continue;
                        adjIslands.insert(grid[nextRow][nextCol]);
                    }
                    for(const auto &elem : adjIslands) {
                        sum += islands[elem];
                    }
                    maxArea = max(maxArea, sum + 1);
                }
            }
        }

        maxArea = max(maxArea, *max_element(islands.begin(), islands.end()));
        return maxArea;
    }
};
