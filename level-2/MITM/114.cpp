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
const ll INF = 1e14;

int n;
ll a[N];

void backtrack(int i, int en, vector<ll>& v, ll cur = 0) {
    if (i > en) {
        v.push_back(cur);
        return;
    }

    for (int j = 0; j < 2; ++j) {
        backtrack(i + 1, en, v, cur + j * a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    ll total = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], total += a[i];

    vector<ll> v1, v2;
    backtrack(1, n/2, v1);
    backtrack(n/2 + 1, n, v2);

    sort(all(v2));
    ll res = INF;
    for (auto sum1 : v1) {
        auto it = lower_bound(all(v2), (total - 2 * sum1) / 2);
        res = min(res, abs(2 * (sum1 + *it) - total));
        if (it != v2.begin()) {
            it--;
            res = min(res, abs(2 * (sum1 + *it) - total));
        }
    }
    cout << res;

    return 0;
}