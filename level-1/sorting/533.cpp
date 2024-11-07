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
    u32 n, q;
    cin >> n >> q;
    vec<ii> points(n);
    i32 max_s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].se >> points[i].fi;
        max_s = max(max_s, points[i].fi);
    }

    sort(rev(points), [] (const ii& a, const ii& b) {
        return a.fi + a.se < b.fi + b.se;
    });

    u64 res = 0;
    for (int i = 0; i < n && q > 0 && points[i].fi + points[i].se >= max_s; ++i, --q) {
        res += (u64) points[i].fi + points[i].se;
    }

    cout << res + 1ll * q * max_s;
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