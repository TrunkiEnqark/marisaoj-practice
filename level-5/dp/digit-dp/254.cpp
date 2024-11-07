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

ll dp[20][2][11][11][2]; // [pos][tight][cur][prev][lead_zero]

ll calc(string num, int pos, bool tight, int cur, int prev, bool leading_zero, int current = 0) {
    // cout << prev << ' ' << cur << ' ' << current << '\n';
    if (pos == sz(num)) return 1;

    ll& res = dp[pos][tight][cur][prev][leading_zero];
    if (res != -1) return res;

    int lim = (tight ? num[pos] - '0' : 9);
    res = 0;

    for (int dig = 0; dig <= lim; ++dig) {
        if (dig == cur || dig == prev) continue;

        int new_cur = cur;
        int new_prev = prev;
        bool new_leading_zero = (leading_zero && (dig == 0));
        if (!new_leading_zero) {
            new_prev = cur;
            new_cur = dig;
        }

        res += calc(num, 
                    pos + 1, 
                    tight && (dig == lim), 
                    new_cur, 
                    new_prev,
                    new_leading_zero,
                    current * 10 + dig);
    }

    return res;
}

ll solve(ll n) {
    memset(dp, -1, sizeof dp);
    return calc(to_string(n), 0, true, 10, 10, true);
} 

bool is_non_palind(ll n) {
    string num = to_string(n);
    for (int i = 1; i < sz(num); ++i) {
        if (num[i] == num[i - 1]) return false;
        if (i > 1 && num[i] == num[i - 2]) return false;
    }
    return true;
}

ll brute_force(ll n) {
    ll res = 0;
    for (ll i = 0; i <= n; ++i)
        res += is_non_palind(i);
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll l, r;
    cin >> l >> r;
    // cout << brute_force(l) << ' ' << brute_force(r) << '\n';
    // cout << solve(l) << ' ' << solve(r) << '\n';
    cout << solve(r) - solve(l) + is_non_palind(l);

    return 0;
}