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
const int N = 1e6 + 5;
const int INF = 1e9;

int n; 
ll k, a[N]; 

ll count_pairs(ll target) {
    ll cnt = 0;
    for (int l = 1, r = 2; r <= n; ++r) {
        while (abs(a[r] - a[l]) > target) l++;
        cnt += (r - l);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    ll lo = 0;
    ll hi = a[n] - a[1];
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        
        ll pairs = count_pairs(mid);
        // cout << mid << ' ' << pairs << '\n';
        if (pairs < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << lo;

    return 0;
}