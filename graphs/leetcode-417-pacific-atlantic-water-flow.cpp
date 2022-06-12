// dfs from borders, stores states in 2d vectors
// time: O(V*E)
// space: O(V*E)
class Solution {
public:
    vector<int> rowDir{1, -1, 0, 0};
    vector<int> colDir{0, 0, 1, -1};
    
    bool valid(int row, int col, int parentRow, int parentCol, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() &&
        grid[parentRow][parentCol] <= grid[row][col];
        // we're flowing in reverse so parent <= child
    }

    void traverse(int row, int col, vector<vector<int>>& grid,
    vector<vector<bool>>& border, vector<vector<bool>>& visited) {
        if(!border[row][col])
            border[row][col] = true;

        for(int i = 0; i < 4; ++i) {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];

            if(!valid(nextRow, nextCol, row, col, grid))
                continue;
            if(border[nextRow][nextCol])
                continue;

            if(!visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                traverse(nextRow, nextCol, grid, border, visited);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacificBorder(rows, vector<bool>(cols));
        vector<vector<bool>> pacificVisited(rows, vector<bool>(cols));

        vector<vector<bool>> atlanticBorder(rows, vector<bool>(cols));
        vector<vector<bool>> atlanticVisited(rows, vector<bool>(cols));

        // populate pacific
        for(int r = 0; r < rows; ++r) {
            int colEnd = 1;
            if(r == 0)
                colEnd = cols;
            for(int c = 0; c < colEnd; ++c) {
                pacificBorder[r][c] = true;
            }
        }

        // populate atlantic
        for(int r = 0; r < rows; ++r) {
            int colStart = cols - 1;
            if(r == rows - 1)
                colStart = 0;
            for(int c = colStart; c < cols; ++c) {
                atlanticBorder[r][c] = true;
            }
        }

        // run dfs from borders
        for(int r = 0; r < rows; ++r) {
            int colEnd = 1;
            if(r == 0)
                colEnd = cols;
            for(int c = 0; c < colEnd; ++c) {
                pacificVisited[r][c] = true;
                traverse(r, c, heights, pacificBorder, pacificVisited);
            }
        }
        for(int r = 0; r < rows; ++r) {
            int colStart = cols - 1;
            if(r == rows - 1)
                colStart = 0;
            for(int c = colStart; c < cols; ++c) {
                atlanticVisited[r][c] = true;
                traverse(r, c, heights, atlanticBorder, atlanticVisited);
            }
        }

        vector<vector<int>> answer;

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(pacificBorder[r][c] && atlanticBorder[r][c])
                    answer.push_back(vector<int>{r, c});
            }
        }

        return answer;
    }
};
