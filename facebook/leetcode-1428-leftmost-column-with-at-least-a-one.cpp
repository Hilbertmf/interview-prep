// solved
// https://leetcode.ca/all/1428.html
// https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
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

// BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
// BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols. 

int getFirstOneBinarySearch(int row, int col, BinaryMatrix &matrix) {
	if(matrix.get(row, 0) == 1) return 0;
	if(matrix.get(row, col-1) == 0) return INF;
	
	int left = 0, right = col-1;
	int mid = left + (right - left)/2;
	
	while(left < right) {
		if(matrix.get(row, mid) == 1) {
			if(mid-1 >= 0 && matrix.get(row, mid-1) == 0) break;
			else {
				right = mid - 1;
			}
		}
		else { // right
			left = mid + 1;
		}
		mid = left + (right - left)/2;
	}
	return mid;
}

int getLeftMostCol(BinaryMatrix &matrix) {
	vector<int> dimensions = matrix.dimensions();
	int row = dimensions[0], col = dimensions[1];
	int firstOne = INF;

	for(int r = 0; r < row; r++) {
		firstOne = min(firstOne, getFirstOneBinarySearch(r, col, matrix));
	}

	if(firstOne == INF) return -1;
	return firstOne;
}

/*
time: O(row*log(col))
space: O(1)
*/