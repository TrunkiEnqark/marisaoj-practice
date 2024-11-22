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

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector<int> pos[26];
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }

    int res = 0;
    for (int i = 0; i < m; ++i) {
        int ch = t[i] - 'a';
        int r = upper_bound(all(pos[ch]), n - m + i) - pos[ch].begin() - 1;
        int l = lower_bound(all(pos[ch]), i) - pos[ch].begin();
        // cout << t[i] << ' ' << l << ' ' << r << endl;
        if (l <= r) res += (r - l + 1);
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