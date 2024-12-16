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

int n, dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
        if (i > 1) dp[i] = (dp[i] + dp[i - 2]) % MOD;
        if (i > 2) dp[i] = (dp[i] + dp[i - 3]) % MOD;
    }
    cout << dp[n];

    return 0;
}