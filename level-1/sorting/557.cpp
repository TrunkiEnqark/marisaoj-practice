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
#define all(a) (a.begin(), a.end())

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    i32 n;
    cin >> n;
    vec<ii> lines(n);
    for (int i = 0; i < n; ++i)
        cin >> lines[i].second >> lines[i].first;
    
    sort(lines.begin(), lines.end());

    i32 res = 0;
    i32 cur = 0;
    i32 last = -1;
    for (int i = 0; i < n; ++i) {
        if (lines[i].second > last) {
            res++;
            last = lines[i].first;
        }
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