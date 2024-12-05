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
const int N = 1e6 + 10;
const int INF = 1e9;

ll l, r;
bool is_prime[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> l >> r;

    memset(is_prime, true, sizeof is_prime);

    for (ll i = 2; i * i <= r; ++i) {
        for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
            is_prime[j - l] = false;
        }
    }
    
    for (ll i = max(2ll, l); i <= r; ++i) 
        if (is_prime[i - l]) 
            cout << i << ' ';

    return 0;
}