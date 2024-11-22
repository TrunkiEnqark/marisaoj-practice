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

    FenwickTree(int _n) : n(_n) {
        f.resize(n + 1, 0);
    }

    void update(int idx) {
        for (; idx <= n; idx += idx & (-idx))
            f[idx]++;
    }

    int get(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & (-idx)) 
            res += f[idx];
        return res;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    vector<ll> comps = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        comps.push_back(a[i]);
    }
    sort(all(comps));

    for (int i = 0; i <= n; ++i) {
        a[i] = lower_bound(all(comps), a[i]) - comps.begin() + 1;
    }

    // for (int i = 0; i <= n; ++i) cout << a[i] << ' '; cout << endl;

    FenwickTree ft (n + 1);
    ll res = 0;
    for (int i = n; i > 0; --i) {
        res += ft.get(a[i] - 1);
        ft.update(a[i]); 
    }
    cout << res;
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