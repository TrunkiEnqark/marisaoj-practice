#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        a[r1][c1]++;
        a[r2 + 1][c1]--;
        a[r1][c2 + 1]--;
        a[r2 + 1][c2 + 1]++;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}