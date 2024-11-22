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
    vector<vector<int>> seg;

    SegmentTree(int _n) : n(_n) {
        seg.resize((n + 1) * 4);
    }

    void build(int id, int l, int r, const vector<int>& a) {
        if (l == r) {
            seg[id].push_back(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(id*2, l, mid, a);
        build(id*2 + 1, mid + 1, r, a);

        seg[id].resize(sz(seg[id*2]) + sz(seg[id*2 + 1]));
        merge(all(seg[id*2]), all(seg[id*2 + 1]), seg[id].begin());
    }

    int get(int id, int l, int r, int ql, int qr, int k) {
        if (l > qr || r < ql || l > r) return 0;
        if (ql <= l && r <= qr) {
            return (int) seg[id].size() - (upper_bound(all(seg[id]), k) - seg[id].begin());
        }
        int mid = (l + r) / 2;
        return get(id*2, l, mid, ql, qr, k) + get(id*2 + 1, mid + 1, r, ql, qr, k);
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
        int l, r, k;
        cin >> l >> r >> k;
        cout << st.get(1, 1, n, l, r, k) << '\n';
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