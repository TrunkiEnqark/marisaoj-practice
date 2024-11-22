#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e16;

struct SegmentTree {
    int n;
    vector<long long> seg;

    SegmentTree(int _n) : n(_n) {
        seg.resize((n + 1) * 4, INF);
    }

    void update(int id, int l, int r, int idx, long long val) {
        if (l > idx || r < idx) return;
        if (l == r) {
            seg[id] = min(seg[id], val);
            return;
        }
        int mid = (l + r) / 2;
        update(id*2, l, mid, idx, val);
        update(id*2 + 1, mid + 1, r, idx, val);
        seg[id] = min(seg[id*2], seg[id*2 + 1]);
    }

    void update(int idx, long long val) {
        update(1, 0, n, idx, val);
    }

    long long get(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return INF;
        if (ql <= l && r <= qr) return seg[id];

        int mid = (l + r) / 2;
        return min(get(id*2, l, mid, ql, qr), get(id*2 + 1, mid + 1, r, ql, qr));
    }

    long long get(int ql, int qr) {
        return get(1, 0, n, ql, qr);
    }
};

struct Node {
    int l, cost;
};

void solve() {
    int n, q;
    cin >> n >> q;
    SegmentTree st(n);

    vector<vector<Node>> adj(n + 1);
    for (int i = 0; i < q; ++i) {
        int l, r, cost;
        cin >> l >> r >> cost;
        adj[r].push_back({l, cost});
    }

    st.update(0, 0); 

    for (int r = 1; r <= n; ++r) {
        if (!adj[r].empty()) {
            for (auto [l, cost] : adj[r]) {
                st.update(r, st.get(l - 1, r) + cost);
            }
        }
    }

    long long res = st.get(n, n);
    cout << (res == INF ? -1 : res) << endl;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    while(t--) solve();

    return 0;
}
