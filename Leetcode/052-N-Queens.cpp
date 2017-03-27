class Solution {
public:
    void helper(int row, int col, int dia, int back_dia, int n, int &count) {
        if (row==n) {
            count++;
            return;
        }
        for (int i=0; i<n; i++) {
            int curr = 1<<i;
            if (curr&col || curr&back_dia || curr&dia)   continue;
            helper(row+1, col|curr, (dia|curr)>>1, (back_dia|curr)<<1, n, count);
        }
    }
    
    int totalNQueens(int n) {
        int count = 0;
        helper(0, 0, 0, 0, n, count);
        return count;
    }
};