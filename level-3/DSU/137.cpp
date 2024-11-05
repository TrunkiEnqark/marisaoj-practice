#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par, sz;

    DSU (int n) : par(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }

    int connected_components(int u) {
        return sz[find(u)];
    }
};

struct Query {
    int e, c, idx;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu(n);
    vector<pair<int, int>> edges(m);
    vector<bool> removed(m, false);
    vector<Query> queries(q);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }


    for (int i = 0; i < q; ++i) {
        int e, c;
        cin >> e >> c;
        e--; c--;
        queries[i].e = e;
        queries[i].c = c;
        queries[i].idx = i;
        removed[e] = true;
    }

    for (int i = 0; i < m; ++i) 
        if (!removed[i]) dsu.unite(edges[i].first, edges[i].second);
    
    reverse(queries.begin(), queries.end());

    vector<int> res(q);
    for (auto query : queries) {
        res[query.idx] = dsu.connected_components(query.c);
        int i = query.e;
        dsu.unite(edges[i].first, edges[i].second);
    }
    for (auto r : res) cout << r << '\n';
}