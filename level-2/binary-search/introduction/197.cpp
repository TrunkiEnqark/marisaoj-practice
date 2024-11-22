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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    if (n == 1) {
        cout << 0;
        return;
    }

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int it = upper_bound(a.begin(), a.end(), a[i] + n - 1) - lower_bound(a.begin(), a.end(), a[i]);
        // cout << it << endl;
        if (it < n) res = max(res, it);
    }
    cout << n - res;
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