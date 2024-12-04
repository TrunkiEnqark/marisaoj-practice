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
const int N = 505;
const int INF = 1e9;

int n, m, k, a[N][N];

int get_sum(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return INF;
    return a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    int res = 0;
    for (int r1 = 1; r1 <= n; ++r1) {
        for (int r2 = r1; r2 <= n; ++r2) {
            
            for (int c1 = 1, c2 = 1; c2 <= m; ++c2) {
                while (c1 < c2 && get_sum(r1, c1, r2, c2) > k) {
                    c1++;
                }
                
                if (get_sum(r1, c1, r2, c2) <= k) 
                    res = max(res, (r2 - r1 + 1) * (c2 - c1 + 1));
            }
        }
    }
    cout << res;

    return 0;
}