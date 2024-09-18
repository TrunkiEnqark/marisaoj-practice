#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

const int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int dy[] = {2, -2, -2, 2, -1, 1, 1, -1};

int result[10][10];

bool is_valid(int u, int v, int n, int m) {
    return (0 <= u && u < n && 0 <= v && v < m && result[u][v] == -1);
}

int count_valid_moves(int u, int v, int n, int m) {
    int cnt = 0;
    for (int k = 0; k < 8; ++k) {
        cnt += is_valid(u + dx[k], v + dy[k], n, m);
    }
    return cnt;
}

bool backtrack(int i, int j, int node, int n, int m) {
    if (node == n * m) {
        return true;
    }


    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> next_moves;
    for (int k = 0; k < 8; ++k) {
        if (is_valid(i + dx[k], j + dy[k], n, m)) {
            int cnt = count_valid_moves(i + dx[k], j + dy[k], n, m);
            next_moves.push({cnt, {i + dx[k], j + dy[k]}});
        }
    }

    while (!next_moves.empty()) {
        auto [_, coord] = next_moves.top();
        auto [x, y] = coord;
        next_moves.pop();
        result[x][y] = node + 1;
        if (backtrack(x, y, node + 1, n, m)) 
            return true;
        result[x][y] = -1;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(result, -1, sizeof result);

    result[0][0] = 1;
    backtrack(0, 0, 1, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << result[i][j] << ' ';
        cout << '\n';
    }
}