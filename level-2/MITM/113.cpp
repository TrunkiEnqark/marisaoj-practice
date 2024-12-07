#include <bits/stdc++.h>

#define NAME ""
#define i32 int
#define i64 int64_t
#define u32 unsigned int
#define u64 unsigned long long
#define ll long long
#define ld long double
#define ii pair<ll, ll>
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

int n;
ii p[N];

struct Hasher {
    size_t operator() (const ii& p) const {
        return (hash<ll>() (p.fi)) ^ (hash<ll>() (p.se) << 32);
    }
};

void backtrack(int i, int en, unordered_map<ii, int, Hasher>& mp, ii cur = {0, 0}) {
    if (i > en) {
        mp[cur]++;
        return;
    }

    for (int j = 0; j < 2; ++j) {
        backtrack(i + 1, en, mp, {cur.fi + j * p[i].fi, cur.se + j * p[i].se});
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> p[i].fi >> p[i].se;

    unordered_map<ii, int, Hasher> mp1, mp2;
    backtrack(1, n/2, mp1);
    backtrack(n/2 + 1, n, mp2);

    ll res = 0;
    for (auto [pi, cnt1] : mp1) {
        ii target = {a - pi.fi, b - pi.se};
        if (mp2.count(target)) {
            res += cnt1 * mp2[target];
        }
    }
    cout << res;

    return 0;
}