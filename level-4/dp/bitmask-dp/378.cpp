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
#define msk(x, i) ((x >> i) & 1)

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 10;
const int INF = 1e9;

int n, m;
ll dp[201][1 << N];

bool check(int mask) {
    for (int i = 1; i < n; ++i) {
        if (msk(mask, i) && msk(mask, i - 1)) return false;
    }
    return true;
}

void print(int mask) {
    for (int i = 0; i < n; ++i) 
        cout << msk(mask, i);
    cout << ' ';
}

void add(ll& a, ll b) {
    a = (a + b) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;

    for (int mask = 0; mask < (1 << n); ++mask)
        if (check(mask)) {
            // print(mask);
            dp[0][mask] = 1;
        }

    for (int j = 1; j < m; ++j) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (!check(mask)) continue;

            for (int pre = 0; pre < (1 << n); ++pre) {
                if (!check(pre)) continue;
                
                bool valid = true;
                for (int i = 0; i < n; ++i) {
                    if (msk(mask, i) && msk(pre, i)) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    // cout << j << ' '; print(pre); print(mask); cout << '\n';
                    add(dp[j][mask], dp[j - 1][pre]);
                }
            }
        }
    }

    // for (int j = 0; j < m; ++j) {
    //     for (int mask = 0; mask < (1 << n); ++mask) {
    //         cout << dp[j][mask] << ' ';
    //     }
    //     cout << '\n';
    // }

    ll res = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        // cout << dp[0][mask] << ' ';
        res = (res + dp[m - 1][mask]) % MOD;
    }
    
    cout << res;

    return 0;
}