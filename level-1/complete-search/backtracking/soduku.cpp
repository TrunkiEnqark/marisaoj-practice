#include <bits/stdc++.h>

using namespace std;

const int base = 511; // 1111111110

int board[9][9];
int row[9], col[9], cell[3][3];

/*
|---|---|---|
|...|...|...|
|.0.|.1.|.2.|
|...|...|...|
|---|---|---|
|...|...|...|
|.3.|.4.|.5.|
|...|...|...|
|---|---|---|
|...|...|...|
|.6.|.7.|.8.|
|...|...|...|
|---|---|---|
cell[0] manages range [0..2][0..2]
cell[1] manages range [0..2][3..5]
cell[2] manages range [0..2][6..8]
cell[3] manages range [3..5][0..2]
...
cell[i][j] manages range [i..3*i - 1][j..3*j - 1]

*/

void init() {
    for (int i = 0; i < 9; ++i) {
        row[i] = col[i] = base;
    }
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j)
            cell[i][j] = base; 
}

bool check() {
    for (int i = 0; i < 9; ++i) 
        if (row[i] != 0 || col[i] != 0) return false;
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j)
            if (cell[i][j] != 0) return false;
    return true;
}

bool backtrack(int i, int j, int n, int m) {
    if (i >= n) {
        return check();
    }

    if (j == m) {
        return backtrack(i + 1, 0, n, m); 
    }

    if (board[i][j] != 0) {
        return backtrack(i, j + 1, n, m);
    }
    int mask = col[j] & row[i] & cell[i/3][j/3];
    for (int k = 1; k <= 9; ++k) {
        if ((mask >> (k - 1)) & 1) {
            board[i][j] = k;
            row[i] ^= (1 << (k - 1));
            col[j] ^= (1 << (k - 1));
            cell[i/3][j/3] ^= (1 << (k - 1));
            
            if (backtrack(i, j + 1, n, m)) 
                return true;

            board[i][j] = 0;
            row[i] ^= (1 << (k - 1));
            col[j] ^= (1 << (k - 1));
            cell[i/3][j/3] ^= (1 << (k - 1));
        }
    }
    return false;
}

int main() {
    init();
    for (int i = 0; i < 9; ++i) 
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) continue;
            row[i] ^= (1 << (board[i][j] - 1));
            col[j] ^= (1 << (board[i][j] - 1));
            cell[i/3][j/3] ^= (1 << (board[i][j] - 1));
        }
    backtrack(0, 0, 9, 9);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}