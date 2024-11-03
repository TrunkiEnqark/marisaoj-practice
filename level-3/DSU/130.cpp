#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par, sz;

    DSU (int n) : par(n), sz(n) {}

    void make_set(int u) {
        par[u] = u;
        sz[u] = 1;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool are_connected(int u, int v) {
        return find(u) == find(v);
    }

    void union_sets(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);

    for (int i = 1; i <= n; ++i) 
        dsu.make_set(i);

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            dsu.union_sets(u, v);
        } else {
            cout << (dsu.are_connected(u, v) ? "YES\n" : "NO\n");
        }
    }
}