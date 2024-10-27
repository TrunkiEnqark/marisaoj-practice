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

int k;
ll dp[12][150][150][2]; // [pos][sum_digits][current_number][tight]

ll calc(string num, int pos, int sum_digits, int current_number, bool tight) {
    if (pos == num.size()) {
        return sum_digits == 0 && current_number == 0;
    }

    ll& res = dp[pos][sum_digits][current_number][tight];
    if (res != -1)
        return res;

    res = 0;
    int lim = (tight ? num[pos] - '0' : 9);
    for (int digit = 0; digit <= lim; ++digit) {
        res += calc(num, 
                    pos + 1, 
                    (sum_digits + digit) % k,
                    (current_number * 10 + digit) % k,
                    tight && (digit == lim));
    }

    return res;
}

ll solve(ll num) {
    memset(dp, -1, sizeof dp);
    return calc(to_string(num), 0, 0, 0, true);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) {
        ll l, r;
        cin >> l >> r >> k;
        if (k > 150) {
            cout << 0 << '\n';
            continue;
        }
        cout << solve(r) - solve(l - 1) << '\n';
    }

    return 0;
}