class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty())  return false;
        const int n = board.size();
        vector<int> count;
        // row
        for (int i=0; i<n; i++) {
            count.assign(9, 0);
            for (int j=0; j<n; j++) {
                if (board[i][j]!='.') {
                    int pos = board[i][j]-'1';
                    if (count[pos]>0)   return false;
                    else    ++count[pos];
                }
            }
        }
        //column
        for (int j=0; j<n; j++) {
            count.assign(9, 0);
            for (int i=0; i<n; i++) {
                if (board[i][j]!='.') {
                    int pos = board[i][j]-'1';
                    if (count[pos]>0)   return false;
                    else    ++count[pos];
                }
            }
        }
        //3*3 chunk
        for (int i=0; i<n; i+=3) {
            for (int j=0; j<n; j+=3) {
                count.assign(9, 0); 
                for (int row=i; row<i+3; row++) 
                    for (int col=j; col<j+3; col++) {
                        if (board[row][col]!='.') {
                            int pos = board[row][col]-'1';
                            if (count[pos]>0)   return false;
                            else    ++count[pos];
                        }
                    }
            }
        }
        return true;
    }
};