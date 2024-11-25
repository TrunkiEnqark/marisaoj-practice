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
const int INF = 1e9;

ll cnt(ll n, ll m, ll x) {
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        res += min(m, x / i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll n, m, k;
    cin >> n >> m >> k;

    ll l = 0, r = n*m;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (cnt(n, m, mid) < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l;

    return 0;
}