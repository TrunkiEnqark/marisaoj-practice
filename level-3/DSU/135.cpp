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

u32 n, q;
vec<i32> height, par, color;
vec<vec<i32>> adj;

void dfs(i32 u, i32 parent = -1) {
    for (auto v : adj[u])
        if (v != parent) {
            height[v] = height[u] + 1;
            par[v] = u;
            dfs(v, u);
        }
}

void solve() {
    cin >> n >> q;
    adj.resize(n + 1);
    height.resize(n + 1, 0);
    par.resize(n + 1, 0);
    color.resize(n + 1, 0);

    for (i32 i = 1; i < n; ++i) {
        i32 u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    // for (int i = 1; i <= n; ++i) cout << height[i] << ' '; cout << endl;
    // for (int i = 1; i <= n; ++i) cout << par[i] << ' '; cout << endl;

    while (q--) {
        i32 u, v, z;
        cin >> u >> v >> z;
        vec<i32> nodes;
        while (height[v] > height[u]) {
            if (color[v] == 0) color[v] = z;
            nodes.push_back(v);
            v = par[v];
        }

        if (color[u] == 0) color[u] = z;
        
        for (auto node : nodes) {
            par[node] = par[u];
        }
    }

    for (int i = 1; i <= n; ++i) cout << color[i] << ' ';
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