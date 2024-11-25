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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& it : a) cin >> it;
    sort(all(a));

    auto check = [&] (int dis) {
        int cnt = 1, last = 0; 
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[last] >= dis) { 
                ++cnt;
                last = i;
                if (cnt == k) return true; 
            }
        }
        return false;
    };

    int lo = 0, hi = 1e9, res = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            lo = mid + 1;
            res = mid;
        } else {
            hi = mid - 1;
        }
    }   
    cout << res << endl;
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
