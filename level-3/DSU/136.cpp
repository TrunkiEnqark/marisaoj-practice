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
// #define sz(a) (u32)(a.size())
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int LG = 20;
const int INF = 1e9;

struct Edge {
    i32 u, v, idx;
    i64 w;

    bool operator < (const Edge& o) const {
        return w < o.w;
    } 
};

struct DSU {
    vec<i32> par, sz;

    // DSU() {}
    DSU(i32 n) : par(n + 1), sz(n + 1, 1) {
        for (i32 i = 1; i <= n; ++i) 
            par[i] = i;
    }

    i32 find(i32 u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void unite(i32 u, i32 v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }

    bool connected(i32 u, i32 v) {
        return find(u) == find(v);
    }
};

struct LCA {
    vec<vec<i32>> par;
    vec<i32> depth;
    vec<vec<i64>> max_edge;

    LCA(int n) : par(n + 1, vec<i32>(LG + 1, 0)), depth(n + 1, 0), max_edge(n + 1, vec<i64>(LG + 1, 0)) {}

    void dfs(const vec<vec<ii>>& g, i32 u, i32 p = -1) {
        for (auto [w, v] : g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            par[v][0] = u;
            max_edge[v][0] = w;

            for (i32 j = 1; j <= LG; ++j) {
                max_edge[v][j] = max(max_edge[v][j - 1], max_edge[par[v][j - 1]][j - 1]);
                par[v][j] = par[par[v][j - 1]][j - 1];
            }
            
            dfs(g, v, u);
        }
    }

    i64 get_max(i32 u, i32 v) {
        i64 res = 0;
        if (depth[u] < depth[v]) swap(u, v);

        i32 diff = depth[u] - depth[v];
        for (i32 i = 0; (1 << i) <= diff; ++i) {
            if (diff & (1 << i)) {
                res = max({res, max_edge[u][i], max_edge[v][i]});
                u = par[u][i];
            }
        }

        if (u == v) return res;

        for (i32 i = LG; i >= 0; --i) {
            if (par[u][i] != par[v][i]) {
                res = max({res, max_edge[u][i], max_edge[v][i]});
                u = par[u][i];
                v = par[v][i];
            }
        }

        return max({res, max_edge[u][0], max_edge[v][0]});
    }
};

void solve() {
    i32 n, m;
    cin >> n >> m;
    vec<Edge> edges(m);
    for (i32 i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].idx = i;
    }

    sort(all(edges));
    DSU dsu(n);

    vec<vec<ii>> g(n + 1);

    i64 mst = 0;
    vec<i64> res(m, 0);
    for (auto [u, v, idx, w] : edges) {
        if (dsu.connected(u, v)) continue;

        dsu.unite(u, v);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
        mst += w;
        res[idx] = -1;
    }

    LCA lca(n);
    lca.dfs(g, 1);

    
    for (auto [u, v, idx, w] : edges) {
        if (res[idx] == -1) res[idx] = mst;
        else res[idx] = mst - lca.get_max(u, v) + w;
    }

    for (auto r : res) 
        cout << (r == mst);
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