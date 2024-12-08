#include <bits/stdc++.h>
#define i64 int64_t
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define fi first
#define se second
#define all(a) a.begin(), a.end()
using namespace std;

const ll MOD = 1e9 + 7;

ll sum(ll n) {
    n %= MOD;
    return n * (n + 1) % MOD * ((MOD + 1) / 2) % MOD;
}

ll sum_range(ll l, ll r) {
    if (l > r) return 0ll;
    return (sum(r) - sum(l - 1) + MOD * MOD) % MOD;
}

ll solve(ll n) {
    ll res = 0;

    ll i = 1, last = 0;
    while (i <= n) {
        ll q = n / i;  
        last = n / q;  
        
        ll count = last - i + 1;  
        ll s = sum_range(i, last);  
        
        res = (res + s * sum(q) % MOD) % MOD;
        
        i = last + 1;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    cout << solve(n) << '\n';
    
    return 0;
}