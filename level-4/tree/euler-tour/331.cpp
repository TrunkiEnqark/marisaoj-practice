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

struct SegmentTree {
    int n;
    vector<ll> seg, lazy;

    SegmentTree(int _n) : n(_n) {
        seg.resize(n * 4 + 4);
        lazy.resize(n * 4 + 4);
    }

    void down(int id, int l, int r) {
        if (lazy[id] != 0) {
            int mid = (l + r) / 2;
            seg[id << 1] += lazy[id] * (mid - l + 1);
            seg[id << 1 | 1] += lazy[id] * (r - mid);
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
            lazy[id] = 0;
        }
    }

    void update(int id, int l, int r, int ql, int qr, ll val) {
        if (l > qr || r < ql) return;
        if (ql <= l && r <= qr) {
            seg[id] += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, ql, qr, val);
        update(id << 1 | 1, mid + 1, r, ql, qr, val);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }

    ll get(int id, int l, int r, int pos) {
        if (l == r) return seg[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        if (pos <= mid) return get(id << 1, l, mid, pos);
        else return get(id << 1 | 1, mid + 1, r, pos);
    }
};

int n, q, timer = 0;
vector<int> st, en;
vector<vector<int>> adj;
vector<bool> vst;

void dfs(int u) {
    st[u] = ++timer;
    vst[u] = true;
    for (auto v : adj[u]) {
        if (!vst[v]) dfs(v);
    }
    en[u] = timer;
}

void solve() {
    cin >> n >> q;
    adj.resize(n + 1); 

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    st.resize(n + 1, 0);
    en.resize(n + 1, 0);
    vst.resize(n + 1, false);
    dfs(1);

    SegmentTree it(n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            ll x;
            cin >> i >> x;
            it.update(1, 1, n, st[i], en[i], x);
        } else {
            int u;
            cin >> u;
            cout << it.get(1, 1, n, st[u]) << '\n';
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
