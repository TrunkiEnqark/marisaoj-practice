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

ll index(ll k) {
    return k / 3 + k / 5 + k / 7 
            - k / (3 * 5) - k / (3 * 7) - k / (5 * 7)
            + k / (3 * 5 * 7);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll k;
    cin >> k;
    ll l = 1, r = 1e18;
    ll res = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (index(mid) >= k) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;

    return 0;
}
