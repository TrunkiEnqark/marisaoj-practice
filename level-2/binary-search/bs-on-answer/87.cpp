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
const ll INF = 1e15;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }

    auto ok = [&] (ll sum) {
        ll cur = 0;
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] > sum) return false;
            if (cur + a[i] <= sum) {
                cur += a[i];
            } else {
                cnt++;
                cur = a[i];
            }
        }
        return cnt <= k;
    };

    ll res = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (ok(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}