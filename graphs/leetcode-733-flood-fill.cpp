vector<int> rowDirections{1, -1, 0, 0};
vector<int> colDirections{0, 0, 1, -1};

// time: O(V + E)
// space: O(V + E)
class Solution {
public:
    
    void fill(int color, int newColor, int row, int col, vector<vector<int>>& image,
    vector<vector<bool>>& visited) {
        for(int i = 0; i < 4; ++i) {
            int nextRow = row + rowDirections[i];
            int nextCol = col + colDirections[i];

            if(nextRow < 0 || nextCol < 0 || nextRow >= image.size() || nextCol >= image[0].size())
                continue;
            if(image[nextRow][nextCol] != color)
                continue;

            if(!visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                fill(color, newColor, nextRow, nextCol, image, visited);
            }
        }

        image[row][col] = newColor;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
        fill(image[sr][sc], newColor, sr, sc, image, visited);
        return image;
    }
};
