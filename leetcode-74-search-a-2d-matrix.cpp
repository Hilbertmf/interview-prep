class Solution {
public:
    // time: O(n+m)
    // space: O(1)
    // binary search tree solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int c = matrix[0].size() - 1;
        
        while(r < matrix.size() && c >= 0) {
            if(target == matrix[r][c]) return true;
            if(target < matrix[r][c]) {
                c--;
            }
            else if(target > matrix[r][c]) {
                r++;
            }
        }
        return false;
    }
    // multiple binary searches solution
    // time: O(row * log(col))
    // space: O(1)
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        for(auto& row : matrix) {
            int left = 0, right = row.size()-1;
            while(left <= right) {
                int mid = left + (right - left)/2;
                if(row[mid] == target) return true;
                else if(row[mid] > target) right = mid - 1;
                else if(row[mid] < target) left = mid + 1;
            }
        }
        
        return false;
    }
};