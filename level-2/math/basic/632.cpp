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

ll n;

ll count_pairs(ll k) {
    ll cnt = n / k;
    return cnt * (cnt + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;

    ll res = 0;
    for (int i = 1; i * i <= n; ++i) {
        res = (res + count_pairs(i) * i) % MOD;

        if (n / i != i) {
            res = (res + count_pairs(n / i) * (n / i)) % MOD;
        }
    }

    cout << res;

    return 0;
}