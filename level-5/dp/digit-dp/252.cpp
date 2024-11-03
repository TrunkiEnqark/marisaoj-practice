#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

ll dp[13][200][2]; 

ll calc(string n, int pos, int sum, bool tight) {
    if (pos == n.size()) return sum;

    ll& res = dp[pos][sum][tight];
    if (res != -1) return res;

    int lim = (tight ? n[pos] - '0' : 9);
    res = 0;
    for (int dig = 0; dig <= lim; ++dig) {
        res += calc(n, pos + 1, sum + dig, tight && (dig == lim));
    }

    return res;
}

ll solve(ll n) {
    memset(dp, -1, sizeof dp);
    return calc(to_string(n), 0, 0, true);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);

    return 0;
}