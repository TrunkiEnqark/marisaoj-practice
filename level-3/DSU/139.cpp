#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> par, rank;

    DSU(int _n) : n(_n), par(_n), rank(_n) {
        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        
        if (rank[u] < rank[v]) swap(u, v);
        par[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<tuple<int,int,int>> queries(q);
    for(int i = 0; i < q; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        queries[i] = {l, r, t};
    }
    
    int ans = 0;
    DSU dsu(2*n + 2); 
    
    for(int i = 0; i < q; i++) {
        auto [l, r, t] = queries[i];
        bool valid = true;
        
        l--;
        int sl = dsu.find(l);
        int sr = dsu.find(r);
        int sl_odd = dsu.find(l + n + 1);
        int sr_odd = dsu.find(r + n + 1);
        
        if (t == 1) {
            if ((sl == sr) || (sl_odd == sr_odd)) valid = false;
            
            if (valid) {
                dsu.unite(sl, sr_odd);
                dsu.unite(sr, sl_odd);
            }
        } else {
            if ((sl == sr_odd) || (sr == sl_odd)) valid = false;
            
            if (valid) {
                dsu.unite(sl, sr);
                dsu.unite(sl_odd, sr_odd);
            }
        }
        
        if (!valid) break;
        ans++;
    }
    
    cout << ans << '\n';
    return 0;
}