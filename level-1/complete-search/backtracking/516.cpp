#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
char board[6][6];

bool is_valid(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

bool is_searched(int i, int j, string target, int k) {
    if (k >= target.size()) return true;

    for (int t = 0; t < 4; ++t) {
        int u = i + dx[t];
        int v = j + dy[t];
        if (is_valid(u, v)) {
            if (board[u][v] == target[k]) {
                char tmp = board[i][j];
                board[i][j] = '?';
                if (is_searched(u, v, target, k + 1))
                    return true;
                board[i][j] = tmp;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    string target;
    cin >> target;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (is_searched(i, j, target, 0)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO";
}