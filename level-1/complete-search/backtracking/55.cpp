#include <bits/stdc++.h>

using namespace std;

int board[4][4];

int backtrack(int i, int j) {
    if (i > 3 || j > 3 || board[i][j] == -1) return 0;

    return max(backtrack(i + 1, j), backtrack(i, j + 1)) + board[i][j];
}

int main() {
    for (int i = 0; i < 4; ++i) 
        for (int j = 0; j < 4; ++j) 
            cin >> board[i][j];
    cout << backtrack(0, 0);
    // cout << result;
}