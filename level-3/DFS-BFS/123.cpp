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
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
vec<vec<char>> grid;
vec<vec<bool>> vst;

int bfs(int u, int v) {
    queue<ii> qu;
    qu.push({u, v});
    vst[u][v] = true;

    i32 cnt = 0;
    while (!qu.empty()) {
        auto [i, j] = qu.front();
        qu.pop();

        // cout << i << ' ' << j << '\n';
        if (grid[i][j] == 'x') cnt++;

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vst[ni][nj] && grid[ni][nj] != '#') {
                qu.push({ni, nj});
                vst[ni][nj] = true;
            } 
        } 
    }

    return cnt;
}

void solve() {
    cin >> n >> m;
    grid.resize(n, vec<char>(m));
    vst.resize(n, vec<bool>(m, false));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> grid[i][j];

    vec<i32> trees;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vst[i][j] && grid[i][j] != '#') {
                i32 comps = bfs(i, j);
                // cout << "---------------------\n";
                if (comps) trees.push_back(comps);
            }
        }
    }
    sort(all(trees));
    for (auto tree : trees) cout << tree << ' ';
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