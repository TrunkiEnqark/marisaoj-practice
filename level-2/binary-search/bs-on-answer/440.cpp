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

int n, k;
double a[N], b[N], c[N];

bool check(double mid) {
    for (int i = 1; i <= n; ++i)
        c[i] = a[i] - mid * b[i];

    sort(c + 1, c + n + 1, greater<double>());
    double tmp = 0;
    for (int i = 1; i <= k; ++i)
        tmp += c[i];
    return tmp >= 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    
    double lo = 0, hi = 1e16;
    while (hi - lo > 1e-6) {
        double mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(4) << lo;

    return 0;
}

// Tutorial: https://oi-wiki.org/misc/frac-programming/