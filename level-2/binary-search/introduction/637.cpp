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
const int N = 2e5 + 5;
const int INF = 1e9;

int n;
ll s, a[N], pre[N], mx[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        mx[i] = max(mx[i - 1], pre[i]);
    }

    // for (int i = 1; i <= n; ++i) cout << mx[i] << ' '; cout << endl;

    int res = -1;
    for (int r = 1; r <= n; ++r) {
        int l = lower_bound(mx, mx + n + 1, pre[r] - s) - mx + 1;
        // cout << l << ' ' << r << endl;
        if (l <= r) res = max(res, r - l + 1);
    }

    cout << res;

    return 0;
}
