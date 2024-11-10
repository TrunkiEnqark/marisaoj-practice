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

struct DSU {
    vec<i32> par, sz, oppo;

    DSU(i32 n) : par(n + 1), sz(n + 1, 1), oppo(n + 1, 0) {
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

    void mark(i32 u, i32 v) {
        if (oppo[u] == 0) oppo[u] = v;
        else unite(oppo[u], v);

        if (oppo[v] == 0) oppo[v] = u;
        else unite(oppo[v], u);
    }

    string check(i32 u, i32 v) {
        if (find(u) == find(v)) return "SAFE";

        if (oppo[v] != 0 && find(u) == find(oppo[v])) return "FATAL";

        return "DUNNO";
    }
};

void solve() {
    i32 n, q;
    cin >> n >> q;
    DSU dsu(n);

    while (q--) {
        i32 type, u, v;
        cin >> type >> u >> v;
        // for (i32 i = 1; i <= n; ++i) cout << dsu.group[i] << ' '; cout << endl;
        if (type == 1) {
            dsu.mark(u, v);
        } else {
            cout << dsu.check(u, v) << '\n';
        }
    }
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