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
const ll INF = 1e16;

struct SegmentTree {
    struct Node {
        ll total, sum, sum_left, sum_right;

        ll query() {
            return max({total, sum, sum_left, sum_right});
        }
    };

    int n;
    vector<Node> seg;

    SegmentTree() {}
    SegmentTree(int _n) : n(_n) {
        seg.resize((n + 1) * 4);
    }

    void unite(Node& root, const Node& left, const Node& right) {
        root.total = left.total + right.total;
        root.sum = max({left.sum, right.sum, left.sum_right + right.sum_left});
        root.sum_left = max({left.sum_left, left.total + right.sum_left});
        root.sum_right = max({right.sum_right, left.sum_right + right.total});
    }

    void build(int id, int l, int r, const vector<int>& a) {
        if (l == r) {
            seg[id] = {a[l], a[l], a[l], a[l]};
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);
        unite(seg[id], seg[id << 1], seg[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql || l > r) return {-INF, -INF, -INF, -INF};
        if (ql <= l && r <= qr) return seg[id];
        int mid = (l + r) >> 1;
        auto left = query(id << 1, l, mid, ql, qr);
        auto right = query(id << 1 | 1, mid + 1, r, ql, qr);
        Node res = {-INF, -INF, -INF, -INF};
        unite(res, left, right);
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SegmentTree st(n);
    st.build(1, 1, n, a);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(1, 1, n, l, r).query() << '\n';
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