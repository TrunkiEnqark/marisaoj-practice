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

ll dp[20][200][2];
bool is_prime[200];

void sieve(int lim) {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i < lim; ++i) 
        if (is_prime[i]) {
            for (int j = i*i; j < lim; j += i) 
                is_prime[j] = false;
        }
}

ll calc(string num, int pos, int sum, bool tight) {
    if (pos == num.size()) 
        return is_prime[sum];
    
    ll& res = dp[pos][sum][tight];
    if (res != -1) return res;

    int lim = (tight ? num[pos] - '0' : 9);
    res = 0;
    for (int digit = 0; digit <= lim; ++digit) {
        res += calc(num, pos + 1, sum + digit, tight && (digit == lim));
    }
    return res;
}

ll count_num(ll n) {
    memset(dp, -1, sizeof dp);
    return calc(to_string(n), 0, 0, true);
}

ll find(ll k) {
    ll lo = 1, hi = 1e18;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (count_num(mid) < k) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return lo;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll k;
    cin >> k;
    sieve(200);
    cout << find(k);

    return 0;
}