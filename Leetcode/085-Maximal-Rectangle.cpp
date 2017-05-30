class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)    return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++)
                height[j] = matrix[i][j] == '1' ? height[j]+1 : 0;
            for (int j = 0; j < n; j++) {
                left[j] = matrix[i][j] == '1' ? max(left[j], cur_left) : 0;
                cur_left = matrix[i][j] == '1' ? cur_left : j+1;
            }
            for (int j = n-1; j >= 0; j--) {
                right[j] = matrix[i][j] == '1' ? min(right[j], cur_right) : n;
                cur_right = matrix[i][j] == '1' ? cur_right : j;
            }
            for (int j = 0; j < n; j++)
                res = max(res, (right[j]- left[j])*height[j]);
        }
        return res;
    }
};