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

const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e9;

ll mul_mod(ll a, ll b, ll mod) {
    a %= mod;
    b %= mod;
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

ll pow_mod(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    
    ll tmp = pow_mod(a, b/2, mod);
    tmp = mul_mod(tmp, tmp, mod);
    if (b & 1) return mul_mod(tmp, a, mod);
    return tmp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll n;
    cin >> n;
    cout << mul_mod(pow_mod(4, n/3, MOD), pow_mod(3, n - n/3, MOD), MOD);

    return 0;
}