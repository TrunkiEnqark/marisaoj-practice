#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> states = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

int n, m;
vector<vector<int>> a, field;

bool is_valid(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

bool is_consistent(int i, int j) {
    for (int p = max(0, i - 1); p <= min(n - 1, i + 1); ++p) {
        for (int q = max(0, j - 1); q <= min(m - 1, j + 1); ++q) {
            int unknown = 0, mines = 0;
            for (auto [dx, dy] : states) {
                int ni = p + dx;
                int nj = q + dy;
                if (!is_valid(ni, nj)) continue;
                if (field[ni][nj] == 1) mines++;
                else if (field[ni][nj] == -1) unknown++;
            }
            if (mines > a[p][q] || mines + unknown < a[p][q]) return false;
        }
    }
    return true;
}

bool backtrack(int i, int j) {
    if (i == n) return true;
    if (j == m) return backtrack(i + 1, 0);

    // try to set (i, j) is mine
    field[i][j] = 1;
    if (is_consistent(i, j) && backtrack(i, j + 1)) 
        return true;
    
    // if it doesn't work
    field[i][j] = 0;
    if (is_consistent(i, j) && backtrack(i, j + 1)) 
        return true;

    field[i][j] = -1;
    
    return false;
}

int main() {
    cin >> n >> m;
    a.resize(n, vector<int>(m, 0));
    field.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    backtrack(0, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
}