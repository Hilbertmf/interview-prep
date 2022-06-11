// dfs solution
// time: O(V*E)
// space: O(V*E)
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    vector<int> rowDir{1, -1, 0, 0};
    vector<int> colDir{0, 0, 1, -1};
    
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }
    
    pair<bool, bool> traverse(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited,
    unordered_set<pair<int, int>, pair_hash>& pacificBorder,
    unordered_set<pair<int, int>, pair_hash>& atlanticBorder, vector<pair<int, int>>& path) {
        
        pair<bool, bool> result(false, false);
        
        if(pacificBorder.find({row, col}) != pacificBorder.end())
            result.first = true;
        if(atlanticBorder.find({row, col}) != pacificBorder.end())
            result.second = true;
                
        for(int i = 0; i < 4; ++i) {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];
            if(!valid(nextRow, nextCol, heights))
                continue;

            if(!visited[nextRow][nextCol] && heights[nextRow][nextCol] <= heights[row][col]) {
                visited[nextRow][nextCol] = true;
                auto p = traverse(nextRow, nextCol, heights, visited, pacificBorder, atlanticBorder, path);
                result.first |= p.first;
                result.second |= p.second;
            }
        }

        if(result.first)
            pacificBorder.insert({row, col});
        if(result.second)
            atlanticBorder.insert({row, col});

        path.push_back({row, col});
        return result;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> cells;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        unordered_set<pair<int, int>, pair_hash> pacificBorder;
        unordered_set<pair<int, int>, pair_hash> atlanticBorder;
        pacificBorder.reserve(2 * (rows + cols));
        atlanticBorder.reserve(2 * (rows + cols));

        // populate pacific
        for(int r = 0; r < rows; ++r) {
            int colEnd = 1;
            if(r == 0)
                colEnd = cols;
            for(int c = 0; c < colEnd; ++c) {
                pacificBorder.insert({r, c});
            }
        }

        // populate atlantic
        for(int r = 0; r < rows; ++r) {
            int colStart = cols - 1;
            if(r == rows - 1)
                colStart = 0;
            for(int c = colStart; c < cols; ++c) {
                atlanticBorder.insert({r, c});
            }
        }

        int i;
        for(int r = 0; r < rows; ++r) {
            
            for(int c = 0; c < cols; ++c) {
                // contains in atlantic and pacific
                if(atlanticBorder.find({r, c}) != atlanticBorder.end() &&
                pacificBorder.find({r, c}) != pacificBorder.end()) {
                    continue;
                }

                vector<pair<int, int>> path;
                visited[r][c] = true;
                traverse(r, c, heights, visited, pacificBorder, atlanticBorder, path);

                // unmark path
                for(const auto &p : path) {
                    visited[p.first][p.second] = false;
                }
            }
        }

        for(const auto &pacificPair : pacificBorder) {
            if(atlanticBorder.find(pacificPair) != atlanticBorder.end())
                cells.push_back(vector<int>{pacificPair.first, pacificPair.second});
        }
        
        return cells;
    }
};
