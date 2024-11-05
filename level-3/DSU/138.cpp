#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par, sz;

    DSU (int n) : par(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int find (int x) {
        return par[x] == x ? x : par[x] = find (par[x]);
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap (u, v);
        par[v] = u;
        sz[u] += sz[v];
    }

    int get_comps(int u) {
        return sz[find(u)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    vector<int> a(n);
    vector<pair<int, int>> queries(q);
    for (auto& i : a) cin >> i;

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    vector<pair<int, int>> sorted(n);
    for (int i = 0; i < n; ++i) {
        sorted[i].first = a[i];
        sorted[i].second = i;
    }

    sort(sorted.begin(), sorted.end());
    sort(queries.begin(), queries.end());

    vector<int> results(q, -1);
    vector<bool> used(n, false);
    int cur_query = 0, cur_array = 0, result = 0;
    while (cur_query < q) {
        int k = queries[cur_query].first;

        for (; cur_array < n && sorted[cur_array].first <= k; ++cur_array) {
            int pos = sorted[cur_array].second;

            if (!used[pos]) {
                used[pos] = true;
                if (pos + 1 < n && a[pos + 1] <= k) {
                    dsu.unite(pos, pos + 1);
                    // used[pos] = used[pos + 1] = true;
                }
                if (pos - 1 >= 0 && a[pos - 1] <= k) {
                    dsu.unite(pos, pos - 1);
                    // used[pos] = used[pos - 1] = true;
                }
            }

            result = max(result, dsu.get_comps(pos));
        }

        results[queries[cur_query].second] = result;
        cur_query++;
    }

    for (auto res : results) cout << res << '\n';
}