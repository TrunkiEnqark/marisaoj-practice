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
const int N = 1e5;
const int INV2 = (MOD + 1) / 2; 

inline void add(int &a, int b) {
    a = (a + b) % MOD;
    if (a < 0) a += MOD;
}

inline int mul_mod(ll a, ll b) {
    return (int)((a * b) % MOD);
}

struct SegmentTree {
    struct Node {
        int val, lazy;
        Node() : val(0), lazy(0) {}
    };
    int n;
    vector<Node> st;

    SegmentTree() {}
    SegmentTree(int _n) : n(_n) {
        st.resize((n + 1) * 4);
    }

    inline void down1(int id, int l, int r) {
        if (l > r) return;
        if (st[id].lazy != 0) {
            int t = st[id].lazy;
            int mid = (l + r) >> 1;

            if (l != r) {
                ll len_left = mid - l + 1;
                ll sum_left = mul_mod(l + mid, INV2);
                add(st[id << 1].val, mul_mod(mul_mod(t, len_left), sum_left));
            
                ll len_right = r - mid;
                ll sum_right = mul_mod(mid + 1 + r, INV2);
                add(st[id << 1 | 1].val, mul_mod(mul_mod(t, len_right), sum_right));
                
                add(st[id << 1].lazy, t);
                add(st[id << 1 | 1].lazy, t);
            }
            st[id].lazy = 0;
        }
    }

    inline void down2(int id, int l, int r) {
        if (l > r) return;
        if (st[id].lazy != 0) {
            int t = st[id].lazy;
            int mid = (l + r) >> 1;

            if (l != r) {
                add(st[id << 1].val, mul_mod(t, (mid - l + 1)));
                add(st[id << 1 | 1].val, mul_mod(t, (r - mid)));
                add(st[id << 1].lazy, t);
                add(st[id << 1 | 1].lazy, t);
            }
            st[id].lazy = 0;
        }
    }

    inline void update1(int ql, int qr, int x, int id, int l, int r) {
        if (l > qr || r < ql || l > r) return;
        if (ql <= l && r <= qr) {
            ll len = r - l + 1;
            ll sum = mul_mod(l + r, INV2);
            add(st[id].val, mul_mod(mul_mod(x, len), sum));
            add(st[id].lazy, x);
            return;
        }
        down1(id, l, r);
        int mid = (l + r) >> 1;
        update1(ql, qr, x, id << 1, l, mid);
        update1(ql, qr, x, id << 1 | 1, mid + 1, r);
        st[id].val = (st[id << 1].val + st[id << 1 | 1].val) % MOD;
    }

    inline void update1(int ql, int qr, int x) {
        update1(ql, qr, x, 1, 1, n);
    }

    inline void update2(int ql, int qr, int bonus, int id, int l, int r) {
        if (l > qr || r < ql || l > r) return;
        if (ql <= l && r <= qr) {
            add(st[id].val, mul_mod(bonus, (r - l + 1)));
            add(st[id].lazy, bonus);
            return;
        }
        down2(id, l, r);
        int mid = (l + r) >> 1;
        update2(ql, qr, bonus, id << 1, l, mid);
        update2(ql, qr, bonus, id << 1 | 1, mid + 1, r);
        st[id].val = (st[id << 1].val + st[id << 1 | 1].val) % MOD;
    }

    inline void update2(int ql, int qr, int add) {
        update2(ql, qr, add, 1, 1, n);
    }

    int get1(int ql, int qr, int id, int l, int r) {
        down1(id, l, r);
        if (l > qr || r < ql || l > r) return 0;
        if (ql <= l && r <= qr) return st[id].val;
        int mid = (l + r) >> 1;
        int left = get1(ql, qr, id << 1, l, mid);
        int right = get1(ql, qr, id << 1 | 1, mid + 1, r);
        return (left + right) % MOD;
    }

    int get1(int ql, int qr) {
        return get1(ql, qr, 1, 1, n);
    }

    int get2(int ql, int qr, int id, int l, int r) {
        down2(id, l, r);
        if (l > qr || r < ql || l > r) return 0;
        if (ql <= l && r <= qr) return st[id].val;
        int mid = (l + r) >> 1;
        int left = get2(ql, qr, id << 1, l, mid);
        int right = get2(ql, qr, id << 1 | 1, mid + 1, r);
        return (left + right) % MOD;
    }

    int get2(int ql, int qr) {
        return get2(ql, qr, 1, 1, n);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SegmentTree seg1(n);
    SegmentTree seg2(n);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            ll x, y;
            cin >> x >> y;
            
            seg1.update1(l, r, x); 
            
            int bonus = (MOD - mul_mod(l, x % MOD)) % MOD; 
            bonus = (bonus + y) % MOD; 
            seg2.update2(l, r, bonus);
        } else {
            int ans = seg1.get1(l, r);
            add(ans, seg2.get2(l, r));
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--) solve();

    return 0;
}