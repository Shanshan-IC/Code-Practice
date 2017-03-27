class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = 0, right = n-1, up = 0, down = m-1, dir = 0;
        for (int k=0, i=0, j=0; k<m*n; k++) {
            res.push_back(matrix[i][j]);
            if (dir == 0) {
                if (j==right) {
                    i++;
                    dir = 1;
                    up++;
                }
                else    j++;
            }  else if (dir == 1) {
                if (i==down) {
                    j--;
                    dir = 2;
                    right--;
                } 
                else  i++;
            } else if (dir == 2) {
                if (j==left) {
                    dir = 3;
                    i--;
                    down--;
                }
                else    j--;
            } else {
                if (i==up) {
                    dir = 0;
                    j++;
                    left++;
                }
                else    i--;
            }
        }
        return res;
    }
};