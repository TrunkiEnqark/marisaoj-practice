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

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vec<i32> a(n);
    for (auto& i : a) cin >> i;
    
    sort(a.begin(), a.end());
    
    int res = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (a[l] + a[r] <= k) {
            l++;
        }

        r--;
        res++;
    }
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