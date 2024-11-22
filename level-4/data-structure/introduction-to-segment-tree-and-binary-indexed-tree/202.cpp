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
    vector<ll> seg;

    SegmentTree() {}
    SegmentTree(int _n) : n(_n) {
        seg.resize((n + 1) * 4);
    }

    void update(int id, int l, int r, int idx, int val) {
        if (l > idx || r < idx || l > r) return;
        if (l == r) {
            seg[id] += val;
            return;
        }

        int mid = (l + r) / 2;
        update(id*2, l, mid, idx, val);
        update(id*2 + 1, mid + 1, r, idx, val);
        seg[id] = min(seg[id*2], seg[id*2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }

    ll get_min(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql || l > r) return LLONG_MAX;
        if (ql <= l && r <= qr) return seg[id];

        int mid = (l + r) / 2;
        return min(get_min(id*2, l, mid, ql, qr), get_min(id*2 + 1, mid + 1, r, ql, qr));
    }

    ll get_min(int ql, int qr) {
        return get_min(1, 1, n, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SegmentTree st = SegmentTree(n);
    for (int i = 1; i <= n; ++i) {
        int v; 
        cin >> v;
        st.update(i, v);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            st.update(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.get_min(l, r) << '\n';
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