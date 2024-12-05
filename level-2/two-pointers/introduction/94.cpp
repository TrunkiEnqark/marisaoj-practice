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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vec<int> a(n);
    for (auto& it : a) cin >> it;

    sort(all(a));
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(all(a), a[i] + k) - a.begin() - 1;
        // cout << i << ' ' << j << endl;
        res = max(res, j - i + 1);
    }
    cout << res;

    return 0;
}