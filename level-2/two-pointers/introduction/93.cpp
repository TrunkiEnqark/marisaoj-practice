#include <bits/stdc++.h>

#define NAME ""
#define i32 int
#define i64 int64_t
#define u32 unsigned int
#define u64 unsigned long long
#define ll long long
#define ld long double
#define ii pair<ll, int>
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

    int n;
    ll x;
    cin >> n >> x;
    
    vec<ii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    
    sort(all(a));

    for (int i = 0; i < n; ++i) {
        int j = i, k = n - 1;
        while (j <= k) {
            ll sum = a[i].fi + a[j].fi + a[k].fi;
            if (sum == x) {
                cout << a[i].se << ' ' << a[j].se << ' ' << a[k].se;
                return 0;
            } else if (sum > x) {
                k--;
            } else {
                j++;
            }
        }
    }

    return 0;
}