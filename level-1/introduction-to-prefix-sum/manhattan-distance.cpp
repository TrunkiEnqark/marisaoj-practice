#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> b(2*n + 1, vector<int>(2*n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            b[i + j - 1][n - i + j] = x;
        }
    int m = 2*n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    auto get_sum = [&](int x, int y, int u, int v) {
        return b[u][v] - b[x - 1][v] - b[u][y - 1] + b[x - 1][y - 1];
    };

    // for (int i = 1; i <= m; ++i) {
    //     for (int j = 1; j <= m; ++j) cout << b[i][j] << ' ';
    //     cout << endl;
    // }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = i + j - 1;
            int y = n - i + j;
            // cout << b[x][y] << endl;
            cout << get_sum(max(1, x - k), max(1, y - k), min(m, x + k), min(m, y + k)) << ' ';
        }
        cout << endl;
    }
}