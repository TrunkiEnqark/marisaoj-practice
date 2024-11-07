#include <bits/stdc++.h>

#define NAME ""
#define i32 int
#define i64 int64_t
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vec vector
#define all(a) (a.begin(), a.end())

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int median(vec<i32> v) {
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
        return v[v.size() / 2 - 1];
    }
    return v[v.size() / 2];
}

void solve() {
    int n;
    cin >> n;
    vec<i32> coords_x(n), coords_y(n);
    for (int i = 0; i < n; ++i)
        cin >> coords_x[i] >> coords_y[i];

    i32 median_x = median(coords_x);
    i32 median_y = median(coords_y);
    i64 dist = 0;
    for (int i = 0; i < n; ++i)
        dist += abs(coords_x[i] - median_x) + abs(coords_y[i] - median_y);

    cout << dist;
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