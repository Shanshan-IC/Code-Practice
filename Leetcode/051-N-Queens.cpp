class Solution {
public:
    void helper(int row, int col, int dia, int back_dia, vector<vector<string>> &res, vector<string> &board, int n) {
        if (row==n) {
            res.push_back(board);
            return;
        }
        for (int i=0; i<n; i++) {
            int curr = 1<<i;
            if (curr&col || curr&back_dia || curr&dia)   continue;
            board[row][i] = 'Q';
            helper(row+1, col|curr, (dia|curr)>>1, (back_dia|curr)<<1,  res, board, n);
            board[row][i] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string dots(n, '.');
        vector<string> board(n, dots);
        vector<vector<string>> res;
        helper(0, 0, 0, 0, res, board, n);
        return res;
    }
};