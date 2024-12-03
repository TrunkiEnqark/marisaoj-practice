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

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& it : a) cin >> it, it--;
    for (auto& it : b) cin >> it;

    int res = 0;
    map<int, int> mp;
    for (int i = 0, j = 0; j < n; ++j) {
        mp[a[j]]++;

        while (i < j && mp[a[j]] > b[a[j]]) {
            mp[a[i]]--;
            i++;
        }

        if (mp[a[j]] <= b[a[j]]) res = max(res, j - i + 1);
    }
    cout << res;

    return 0;
}