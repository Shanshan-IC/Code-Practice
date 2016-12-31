#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int board[3][3];
int ans[3][3];
int record[9] = {0};

int cnt = 0;
bool flag;

bool isValid() {
    for (int i=0; i<3; i++) {
        if (board[i][0] + board[i][1] + board[i][2] != 15)
            return false;
        
        if (board[0][i] + board[1][i] + board[2][i] != 15)
            return false;
    }
    if (board[0][0] + board[1][1] + board[2][2] != 15) {
        return false;
    }
    if (board[2][0] + board[1][1] + board[0][2] != 15) {
        return false;
    }
    return true;
    
}

void dfs(int i, int j) {
    if (i==3 && isValid())  {
        cnt++;
        memcpy(ans, board, sizeof(board));
        return;
    }
    else if (board[i][j]) {
        if (j==2)   dfs(i+1, 0);
        else     dfs(i, j+1);
    }
    else {
        for (int k=0; k<9; k++) {
            if (!record[k]) {
                record[k] = 1;
                board[i][j] = k+1;
                if (j==2)   dfs(i+1, 0);
                else    dfs(i, j+1);
                record[k] = 0;
                board[i][j] = 0;
            }
        }
        
    }
}

int main() {
    flag = false;
    int a;
    
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++) {
            cin >> a;
            board[i][j] = a;
            if (a!=0)   record[a-1] = 1;
        }
    
    dfs(0, 0);
    if (cnt == 1 )
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    else
        cout << "Too Many" << endl;
    
    return 0;
}