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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    ll a, b;
    cin >> a >> b;

    ll res = 0;
    for (ll i = sqrt(a) + 1; i < (ll) sqrt(b); ++i) {
        // cout << i << ' ' << (i + 1) * (i + 1) << ' ' << i * i << '\n';
        res += ((i + 1) * (i + 1) - i * i) * i;
    }
    
    ll id_l = sqrt(a);
    res += ((id_l + 1) * (id_l + 1) - a) * id_l;

    ll id_r = sqrt(b);
    res += (b - id_r * id_r + 1) * id_r;
    
    cout << res;

    return 0;
}