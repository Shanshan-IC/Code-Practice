class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        typedef pair<int, int> p;
        queue<p> q;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                if (matrix[i][j] == 1) 
                    ans[i][j] = -1;
                else
                    q.push(p(i, j));
            }
        
        p direct[4] = {p(-1, 0), p(1,0),p(0,1), p(0, -1)};
        while (q.size() > 0) {
            p temp = q.front();
            for (int i = 0; i < 4; i++) {
                int x = temp.first+direct[i].first;
                int y = temp.second+direct[i].second;
                if (x>=0 && x<n && y>=0 && y<m) 
                    if (ans[x][y] == -1) {
                        ans[x][y] = ans[temp.first][temp.second]+1;
                        q.push(p(x, y));
                    }
            }
            q.pop();
        }
        return ans;
        
    }
};