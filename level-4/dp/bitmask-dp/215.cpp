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
#define index(x, i) ((x >> i) & 1)

using namespace std;

const int MOD = 1e9 + 7;
const int N = 20;
const int INF = 1e9;

int n, a[N][N], dp[N][1 << N];

void print(int mask) {
    for (int i = 0; i < n; ++i) 
        cout << index(mask, i);
    cout << ' ';
}

int dfs(int i, int mask) {
    if (!mask) return a[i][0];
    if (dp[i][mask] != -1) return dp[i][mask];

    int& res = dp[i][mask];
    res = INF;
    for (int pre = mask; pre; pre = pre & (pre - 1)) {
        int j = __builtin_ctz(pre);
        res = min(res, dfs(j, mask ^ (1 << j)) + a[i][j]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, (1 << n) - 1);

    return 0;
}