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

int n;
ll a[N], x;

void build(int l, int r, unordered_map<ll, pair<int, int>>& mp) {
    for (int i = l; i <= r; ++i) 
        for (int j = i + 1; j <= r; ++j) 
            mp[a[i] + a[j]] = {i, j};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    unordered_map<ll, pair<int, int>> mp;
    build(1, n, mp);

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (mp.count(a[i] + a[j])) {
                auto [k, p] = mp[x - a[i] - a[j]];
                if (j < k) {
                    // cout << i << ' ' << j << ' ' << k << ' ' << p << '\n';
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";

    return 0;
}