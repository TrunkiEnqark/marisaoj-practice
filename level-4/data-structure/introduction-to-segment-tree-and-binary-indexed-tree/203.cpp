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

struct FenwickTree {
    int n;
    vector<ll> f;

    FenwickTree() {}
    FenwickTree(int _n) : n(_n) {
        f.resize(n + 1, 0);
    }

    void update(int idx, ll val) {
        for (; idx <= n; idx += idx & (-idx)) 
            f[idx] += val;
    }

    void range_update(int l, int r, ll val) {
        update(l, val);
        update(r + 1, -val);
    }

    ll get_sum(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & (-idx))
            res += f[idx];
        return res;
    }
};

FenwickTree ft1, ft2;
int n, q;

void range_add(int l, int r, ll x) {
    ft1.update(l, x);
    ft1.update(r + 1, -x);
    ft2.update(l, x * (l - 1));
    ft2.update(r + 1, -x * r);
}

ll prefix_sum(int idx) {
    return ft1.get_sum(idx) * idx - ft2.get_sum(idx);
}

ll range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
}

void solve() {
    cin >> n >> q;

    ft1 = FenwickTree(n);
    ft2 = FenwickTree(n);

    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        range_add(i, i, val);
    }

    while (q--) {
        int type;
        cin >> type;
        // for (int i = 1; i <= n; ++i) {
        //     cout << ft.get_sum(i, i) << ' ';
        // }
        // cout << '\n';
        if (type == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            range_add(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << range_sum(l, r) << '\n';
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