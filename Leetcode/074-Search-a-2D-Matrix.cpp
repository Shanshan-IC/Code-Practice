class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int col = n-1, row = 0;
        while(col>=0 && row<m) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col--;
            else    row++;
        }
        return false;
    }
};