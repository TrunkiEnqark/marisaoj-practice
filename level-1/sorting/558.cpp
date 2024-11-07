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

void solve() {
    u32 n;
    cin >> n;
    vec<i32> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n != 0) {
        cout << -1;
        return;
    }

    i64 avg = sum / n;
    vector<i32> b(n);
    b[0] = a[0] - avg;
    for (int i = 1; i < n; ++i)
        b[i] = b[i - 1] + a[i] - avg;

    sort(all(b));
    i32 median = b[sz(b) / 2 - (sz(b) % 2 == 0)];

    i64 res = 0;
    for (int i = 0; i < n; ++i)
        res += abs(b[i] - median);
    cout << res;
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}