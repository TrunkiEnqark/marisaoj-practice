#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par;

    DSU (int n) : par(n) {
        for (int i = 1; i <= n; ++i) 
            par[i] = i;        
    }

    int find(int i) {
        if (par[i] == i) return i;
        return par[i] = find(par[i]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            par[v] = u;
            return false;
        }
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;

    bool operator < (const Edge& other) const {
        return w < other.w;
    }
};

int n, m;
vector<Edge> edges;

int main() {
    cin >> n >> m;
    
    DSU dsu(n + 1);

    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    long long res = 0;
    for (auto [u, v, w] : edges) {
        if (!dsu.merge(u, v)) {
            res += w;
        }
    }

    cout << res;
}