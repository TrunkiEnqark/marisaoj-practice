#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int dy[] = {2, -2, -2, 2, -1, 1, 1, -1};

bool vst[10][10];
int result[10][10];

bool backtrack(int i, int j, int node, int n, int m) {
    if (node == n * m) {
        return true;
    }

    for (int k = 0; k < 8; ++k) {
        int u = i + dx[k];
        int v = j + dy[k];
        if (0 <= u && u < n && 0 <= v && v < m && !vst[u][v]) {
            vst[u][v] = true;
            result[u][v] = node + 1;
            bool is_finished = backtrack(u, v, node + 1, n, m);
            if (is_finished) return true;
            vst[u][v] = false;
            result[u][v] = -1;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(result, -1, sizeof result);
    memset(vst, false, sizeof vst);

    result[0][0] = 1;
    vst[0][0] = true;    
    backtrack(0, 0, 1, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << result[i][j] << ' ';
        cout << '\n';
    }
}