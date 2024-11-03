#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

struct DSU {
    vector<int> par, sz, sum;

    DSU (int n) : par(n), sz(n), sum(n) {}

    void make_set(int u) {
        par[u] = u;
        sz[u] = 1;
        sum[u] = u;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void union_sets(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
            sum[u] += sum[v];
        }
    }

    int get_sum(int u) {
        return sum[find(u)];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n, q;
    cin >> n >> q;

    DSU dsu(n + 1);
    for (int i = 1; i <= n; ++i) 
        dsu.make_set(i);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            dsu.union_sets(u, v);
        } else {
            int u;
            cin >> u;
            cout << dsu.get_sum(u) << '\n';
        }
    }

    return 0;
}