#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl 

vector<int> levelDirections {0, 0, 0, 0, 1, -1};
vector<int> rowDirections {1, -1, 0, 0, 0, 0};
vector<int> colDirections {0, 0, 1, -1, 0, 0};

struct position {
    int level;
    int row;
    int col;
    int distance;
};

int bfs(int startLevel, int startRow, int startCol,
int exitLevel, int exitRow, int exitCol,
vector<vector<vector<char>>>& dungeon, vector<vector<vector<bool>>>& visited) {

    struct position p = {startLevel, startRow, startCol, 0};
    queue<position> q;
    q.push(p);

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        if(visited[pos.level][pos.row][pos.col])
            continue;

        visited[pos.level][pos.row][pos.col] = true;

        if(dungeon[pos.level][pos.row][pos.col] == 'E')
            return pos.distance;

        for(int i = 0; i < 6; ++i) {
            int nextLevel = pos.level + levelDirections[i];
            int nextRow = pos.row + rowDirections[i];
            int nextCol = pos.col + colDirections[i];

            if(nextLevel < 0 || nextRow < 0 || nextCol < 0 ||
            nextLevel >= dungeon.size() || nextRow >= dungeon[0].size() ||
            nextCol >= dungeon[0][0].size() ||
            dungeon[nextLevel][nextRow][nextCol] == '#' || visited[nextLevel][nextRow][nextCol])
                continue;
            
            struct position newPos = {nextLevel, nextRow, nextCol, pos.distance + 1};
            // q.push(newPos);
            q.push((position){.level=nextLevel, .row=nextRow, .col=nextCol,
            .distance=pos.distance + 1}); // compound literal
        }
    }
    return -1;
}

int main() {

    int levels = 1, rows = 1, cols = 1;

    while( !(levels == 0 && rows == 0 && cols == 0)) {

        cin >> levels >> rows >> cols;
        if(levels == 0 && rows == 0 && cols == 0) break;

        vector<vector<char>> level2d(rows, vector<char>(cols));
        vector<vector<vector<char>>> dungeon(levels, level2d);
        
        vector<vector<bool>> visited2d(rows, vector<bool>(cols));
        vector<vector<vector<bool>>> visited(levels, visited2d);

        int startLevel = 0, startRow = 0, startCol = 0;
        int exitLevel = 0, exitRow = 0, exitCol = 0;

        for(int level = 0; level < levels; ++level) {
            for(int r = 0; r < rows; ++r) {
                for(int c = 0; c < cols; ++c) {
                    cin >> dungeon[level][r][c];
                    if(dungeon[level][r][c] == 'S') {
                        startLevel = level;
                        startRow = r;
                        startCol = c;
                    }
                    else if(dungeon[level][r][c] == 'E') {
                        exitLevel = level;
                        exitRow = r;
                        exitCol = c;
                    }
                }
            }
            cin.ignore();
        }

        int distance = bfs(startLevel, startRow, startCol, exitLevel, exitRow, exitCol, dungeon, visited);

        if(distance != -1) {
            cout << "Escaped in " << distance << " minute(s)." << "\n";
        }
        else {
            cout << "Trapped!" << "\n";
        }

    }

    return 0;
}