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
#define sz(a) (u32)(a.size())
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    u32 n;
    cin >> n;
    vec<string> a(n);
    for (auto& it : a) cin >> it;

    sort(rev(a), [] (const string& a, const string& b) {
        // for (int i = 0; i < min(sz(a), sz(b)); ++i) 
        //     if (a[i] < b[i]) return true;
        //     else if (a[i] > b[i]) return false;
        // return sz(a) < sz(b);
        return a + b < b + a;
    });

    for (auto i : a) cout << i;
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