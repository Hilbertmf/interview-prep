#include <bits/stdc++.h>
using namespace std;

struct position {
    int row;
    int col;
    int level;
};

vector<int> rowDirections{1, -1, 0, 0};
vector<int> colDirections{0, 0, 1, -1};

bool dfs(int startRow, int startCol, int exitRow, int exitCol, vector<vector<char>>& dungeon,
vector<vector<bool>>& visited) {
    if(dungeon[startRow][startCol] == 'E') return true;
    
    if(!visited[startRow][startCol]) {
        visited[startRow][startCol] = true;

        for(int i = 0; i < 4; ++i) {
            int nextRow = startRow + rowDirections[i];
            int nextCol = startCol + colDirections[i];

            if(nextRow < 0 || nextCol < 0 ||
            nextRow >= dungeon.size() || nextCol >= dungeon[0].size() )
                continue;
            if(dungeon[nextRow][nextCol] == '#')
                continue;
            if(dfs(nextRow, nextCol, exitRow, exitCol, dungeon, visited))
                return true;
        }        
    }

    return false;
}

int bfs(int startRow, int startCol, int exitRow, int exitCol, vector<vector<char>>& dungeon,
vector<vector<bool>>& visited) {
    queue<position> q;
    struct position pos = {startRow, startCol, 0};
    q.push(pos);

    while (!q.empty()) {
        auto currPos = q.front();
        q.pop();

        if(visited[currPos.row][currPos.col]) continue;

        visited[currPos.row][currPos.col] = true;
        if(dungeon[currPos.row][currPos.col] == 'E')
            return currPos.level;
        
        for(int i = 0; i < 4; ++i) {
            int nextRow = currPos.row + rowDirections[i];
            int nextCol = currPos.col + colDirections[i];
            
            if(nextRow < 0 || nextCol < 0 || nextRow >= dungeon.size() ||
            nextCol >= dungeon[0].size() || dungeon[nextRow][nextCol] == '#')
                continue;
            
            struct position newPos = {nextRow, nextCol, currPos.level + 1};
            q.push(newPos);
        }
    }

    return -1;
}



int main() {

    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> dungeon(rows, vector<char>(cols));
    bool possible = false;
    int startRow = 0, startCol = 0;
    int exitRow = 0, exitCol = 0;

    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < cols; ++c) {
            cin >> dungeon[r][c];
            if(dungeon[r][c] == 'S') {
                startRow = r;
                startCol = c;
            }
            else if(dungeon[r][c] == 'E') {
                exitRow = r;
                exitCol = c;
            }
        }
    }

    cout << "dungeon layout:" << "\n";
    for(auto &row : dungeon) {
        for(auto &col : row) {
            cout << col;
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "can i escape the dungeon from position (" << startRow << ", " << startCol <<  ") ?" << "\n";
    cout << "exit is at (" << exitRow << ", " << exitCol << ")" << "\n";    
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    // possible = dfs(startRow, startCol, exitRow, exitCol, dungeon, visited);
    int distance = bfs(startRow, startCol, exitRow, exitCol, dungeon, visited);

    if(distance != -1) {
        cout << "yes" << "\n";
        fill(visited.begin(), visited.end(), vector<bool>(cols, false));
        cout << "distance: " << bfs(startRow, startCol, exitRow, exitCol, dungeon, visited) << "\n";
    }
    else {
        cout << "no" << "\n";
    }
    return 0;
}