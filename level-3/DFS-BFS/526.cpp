#include <bits/stdc++.h>

#define NAME ""
#define i32 int
#define i64 int64_t
#define u32 unsigned int
#define u64 unsigned long long
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vec vector
#define fi first
#define se second
#define sz(a) (u32)(a.size())
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

u32 n, m;
vec<vec<char>> grid;
vec<vec<bool>> vst;
bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(int u, int v) {
    queue<ii> q;

    q.push({u, v});
    vst[u][v] = true;

    int cnt = 0;
    bool ok = true;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (grid[i][j] == '.') ok = false;
        cnt++;

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (is_valid(ni, nj) && !vst[ni][nj] && grid[ni][nj] != 'B') {
                vst[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    if (ok) return cnt;
    return 0;
}

void solve() {
    cin >> n >> m;
    grid.resize(n, vec<char>(m));
    vst.resize(n, vec<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            cin >> grid[i][j];
    }

    i32 res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vst[i][j] && grid[i][j] == 'W') {
                res += bfs(i, j);
            }
        }
    }
    cout << res;
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}