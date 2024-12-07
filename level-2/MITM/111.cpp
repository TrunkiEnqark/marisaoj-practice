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
#define fi first
#define se second
#define sz(a) (u32)(a.size())
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e9;

int n;
ll w[N], v[N], s;

void build(int i, int en, vector<pair<ll, ll>>& mp, ll cur_w = 0, ll cur_v = 0) {
    if (i > en) {
        mp.push_back({cur_w, cur_v});
        return;
    }

    for (int j = 0; j < 2; ++j) {
        build(i + 1, en, mp, cur_w + j * w[i], cur_v + j * v[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    vector<pair<ll, ll>> v1, v2;
    build(1, n/2, v1);
    build(n/2 + 1, n, v2);

    sort(all(v1));
    sort(all(v2));

    for (int i = 1; i < v2.size(); ++i) {
        v2[i].second = max(v2[i].second, v2[i - 1].second);
    }

    ll res = 0;
    for (auto [weight, value] : v1) {
        auto it = upper_bound(all(v2), make_pair(s - weight, LLONG_MAX));
        if (it != v2.begin()) {
            it--;
            res = max(res, value + it->second);
        }
    }

    cout << res;

    return 0;
}