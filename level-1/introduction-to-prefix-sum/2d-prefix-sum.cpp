#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    
    while (q--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1] << '\n';
    }
}