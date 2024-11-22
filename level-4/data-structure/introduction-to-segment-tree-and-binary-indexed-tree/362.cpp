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
    vector<array<int, 2>> seg;
    vector<int> lazy;

    SegmentTree() {}
    SegmentTree(int _n) : n(_n) {
        seg.resize((n + 1) * 4);
        lazy.resize((n + 1) * 4, 0);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            seg[id][0] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        unite(id);
    }

    void down(int id, int l, int r) {
        if (l > r) return;
        if (lazy[id]) swap(seg[id][0], seg[id][1]);
        if (l != r) {
            lazy[id << 1] ^= lazy[id];
            lazy[id << 1 | 1] ^= lazy[id];    
        }
        lazy[id] = 0;
    }

    void unite(int id) {
        seg[id][0] = seg[id << 1][0] + seg[id << 1 | 1][0];
        seg[id][1] = seg[id << 1][1] + seg[id << 1 | 1][1];
    }
        
    void update(int id, int l, int r, int ql, int qr) {
        down(id, l, r);
        if (l > qr || r < ql || l > r) return;
        if (ql <= l && r <= qr) {
            lazy[id] ^= 1;
            down(id, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, ql, qr);
        update(id << 1 | 1, mid + 1, r, ql, qr);
        unite(id);
    }

    int get(int id, int l, int r, int ql, int qr) {
        down(id, l, r);
        if (l > qr || r < ql || l > r) return 0;
        if (ql <= l && r <= qr) return seg[id][1];
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid + 1, r, ql, qr);
    }
};  

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);

    SegmentTree bit[30];
    for (int i = 0; i < 30; ++i) {
        bit[i] = SegmentTree(n);
        bit[i].build(1, 1, n);
    }

    vector<int> p(30, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 30; ++j) {
            if (a[i] & (1 << j)) p[j] ^= 1;
            if (p[j]) bit[j].update(1, 1, n, i, i);
        }
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            for (int j = 0; j < 30; ++j) {
                if ((a[i] & (1 << j)) != (x & (1 << j))) {
                    bit[j].update(1, 1, n, i, n);
                }
            }
            a[i] = x;
        } else {
            int l, r;
            cin >> l >> r;
            
            ll ans = 0;
            for (int j = 0; j < 30; ++j) {
                int cnt = bit[j].get(1, 1, n, max(1, l-1), r);
                ans += 1ll * (r - l - cnt + 2) * cnt * (1 << j);
            }
            cout << ans << '\n';
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