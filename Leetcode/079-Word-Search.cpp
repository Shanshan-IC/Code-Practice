class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty())  return false;
        const int m = board.size();
        const int n = board[0].size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (board[i][j]==word[0])
                    if (helper(board, word, i, j, 0, m, n))
                        return true;
        return false;
    }
    
    bool helper(vector<vector<char>> &board, string word, int i, int j, int pos, int m, int n) {
        if (pos==word.size())   return true;
        if (i<0 || j<0 || i>=m || j>=n || board[i][j]=='@' || board[i][j]!=word[pos])
            return false;
        char temp = board[i][j];
        board[i][j] = '@';
        if (helper(board, word, i-1, j, pos+1, m, n) || helper(board, word, i+1, j, pos+1, m, n) || helper(board, word, i, j-1, pos+1, m, n) | helper(board, word, i, j+1, pos+1, m, n))
            return true;
        board[i][j] = temp;
        return false;
    }
};