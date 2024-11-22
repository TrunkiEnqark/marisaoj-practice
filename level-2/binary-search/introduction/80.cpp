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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto& it : a) cin >> it;
    sort(all(a));

    // for (auto it : a) cout << it << ' '; cout << endl;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        int ni = lower_bound(a.begin() + i, a.end(), l - a[i]) - a.begin();
        int nj = upper_bound(a.begin() + ni + 1, a.end(), r - a[i]) - a.begin() - 1;
        // cout << ni << ' ' << i << ' ' << nj << endl;
        if (ni < nj) res += (nj - ni + 1) - (ni <= i && i <= nj);
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