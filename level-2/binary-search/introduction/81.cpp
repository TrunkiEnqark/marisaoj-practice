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
    int n, q;
    cin >> n >> q;
    vector<ii> candies(n);
    for (auto& [i, j] : candies) cin >> i >> j;

    sort(all(candies), [] (const ii& a, const ii& b) {
        return a.se < b.se;
    });

    vector<ll> idx(n);
    idx[0] = candies[0].fi;
    for (int i = 1; i < n; ++i) {
        idx[i] = idx[i - 1] + candies[i].fi;
    }

    while (q--) {
        ll k;
        cin >> k;
        auto it = lower_bound(all(idx), k) - idx.begin();
        cout << candies[it].se << '\n';
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