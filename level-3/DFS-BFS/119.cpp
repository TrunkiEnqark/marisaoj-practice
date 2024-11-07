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
const int N = 1e3 + 5;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
vec<vec<i32>> grid, dist;
vec<vec<bool>> vst;

i32 bfs(i32 i, i32 j) {
    queue<ii> qu;
    qu.push({i, j});
    dist[i][j] = 0;
    vst[i][j] = true;

    while (!qu.empty()) {
        auto [u, v] = qu.front();
        qu.pop();

        if (u == n - 1 && v == m - 1) return dist[u][v];

        for (int k = 0; k < 4; ++k) {
            u32 ni = u + dx[k];
            u32 nj = v + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vst[ni][nj] 
                && grid[ni][nj] != 1 && dist[ni][nj] > dist[u][v] + 1) {
                qu.push({ni, nj});
                vst[ni][nj] = true;
                dist[ni][nj] = dist[u][v] + 1;
            }
        }
    }
    return -1;
}

void solve() {
    cin >> n >> m;
    grid.resize(n, vec<i32>(m));
    vst.resize(n, vec<bool>(m, false));
    dist.resize(n, vec<i32>(m, INF));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    
    cout << bfs(0, 0);
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