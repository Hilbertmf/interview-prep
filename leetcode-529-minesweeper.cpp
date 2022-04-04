#include <bits/stdc++.h> 
using namespace std; 
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
#define MID(l, r) (l + (r - l) / 2) 
#define CEILDIVISION(x, y) ((x + y - 1) / y) 
#define INF (int)1e9 
#define LONGINF (long long)1e18 
#define MEM(arr, val) memset(arr, (val), sizeof(arr)) 
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
const int MOD = 1000000007; // 10^9 - 7 

vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};


bool isValid(int row, int col, int n, int m) {
	return row >= 0 && row < n && col >= 0 && col < m;
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
	int row = click[0];
	int col = click[1];
	int n = board.size();
	int m = board[0].size();

	if(board[row][col] == 'M' || board[row][col] == 'X') {
		board[row][col] = 'X';
		return board;
	}

	// check directions for mines:
	int numAdjacents = 0;
	for(auto& dir : dirs) {
		int newRow = row + dir[0];
		int newCol = col + dir[1];

		if(isValid(newRow, newCol, n, m) && board[newRow][newCol] == 'M') {
			numAdjacents++;
		}
	}

	if(numAdjacents > 0) {
		board[row][col] = '0' + numAdjacents;
		return board;
	}
	
	board[row][col] = 'B'; // blank square
	// dfs for all valid directions:
	for(auto& dir : dirs) {
		int newRow = row + dir[0];
		int newCol = col + dir[1];

		if(isValid(newRow, newCol, n, m) && board[newRow][newCol] == 'E') {
			vector<int> newClick = {newRow, newCol};
			updateBoard(board, newClick);
		}
	}

	return board;
}

void printMatrix(vector<vector<char>>& board) {
	for(auto vec : board) {
		for(auto c : vec) {
			cout << c;
		}
		cout << endl;
	}
}

int main() { 
	FASTIO;
	vector<int> click(2);
	int n, m;
	
	std::cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> board[i][j];
		}
	}
	std::cin >> click[0] >> click[1];
	board = updateBoard(board, click);
	printMatrix(board);
	
	return 0; 
}
