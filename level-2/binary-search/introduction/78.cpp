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

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> pre(n + 1, 0);
    for (int x, i = 1; i <= n; ++i) {
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    // for (auto it : pre) cout << it << ' '; cout << endl;

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = lower_bound(all(pre), pre[i - 1] + k);
        if (it != pre.end()) {
            int j = it - pre.begin();
            // cout << i << ' ' << j << ' ' << pre[j] - pre[i - 1] << endl;
            res += (n - j + 1);
        }
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