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
    u32 n;
    cin >> n;
    vec<ii> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first;
    for (int i = 0; i < n; ++i)
        cin >> a[i].second;

    sort(rev(a));

    vec<i32> max_change(n), max_b(n);

    max_b[n - 1] = a[n - 1].se;
    max_change[0] = a[0].se - a[0].fi;

    for (int i = 1; i < n; ++i) max_change[i] = max(max_change[i - 1], a[i].se - a[i].fi);
    for (int i = n - 2; i >= 0; --i) max_b[i] = max(max_b[i + 1], a[i].se);
    i64 cur = 0;
    for (int k = 0; k < n; ++k) {
        cur += a[k].fi;
        cout << max(cur + max_change[k], cur - a[k].fi + max_b[k]) << ' ';
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