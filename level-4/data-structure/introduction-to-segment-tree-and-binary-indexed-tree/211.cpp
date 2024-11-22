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
    vector<array<int, 3>> seg;
    vector<int> lazy;

    SegmentTree(int _n) : n(_n) {
        seg.resize((n + 1) * 4);
        lazy.resize((n + 1) * 4);
    }

    void unite(int id) {
        for (int t = 0; t < 3; ++t) 
            seg[id][t] = seg[id*2][t] + seg[id*2 + 1][t];
    }

    void build(int id, int l, int r, const vector<int>& a) {
        if (l == r) {
            seg[id][a[l] % 3]++;
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a);
        build(id * 2 + 1, mid + 1, r, a);
        unite(id);
    }

    void down(int id, int l, int r) {
        if (lazy[id] != 0) {
            int add = lazy[id];
            lazy[id] = 0;

            for (int i = 0; i < add; ++i) {
                swap(seg[id][0], seg[id][2]);
                swap(seg[id][1], seg[id][2]);
            }

            if (l != r) {
                lazy[id * 2] = (lazy[id * 2] + add) % 3;
                lazy[id * 2 + 1] = (lazy[id * 2 + 1] + add) % 3;
            }
        }
    }

    void update(int id, int l, int r, int ql, int qr) {
        down(id, l, r);
        if (l > qr || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[id] = (lazy[id] + 1) % 3;
            down(id, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, ql, qr);
        update(id * 2 + 1, mid + 1, r, ql, qr);
        unite(id);
    }

    int query(int id, int l, int r, int ql, int qr) {
        down(id, l, r);
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[id][0];

        int mid = (l + r) / 2;
        return query(id * 2, l, mid, ql, qr) + query(id * 2 + 1, mid + 1, r, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    SegmentTree st(n);
    st.build(1, 1, n, a);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            st.update(1, 1, n, l, r);
        } else {
            cout << st.query(1, 1, n, l, r) << '\n';
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
