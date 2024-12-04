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
    vector<ii> elements;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            elements.push_back({x, i});
        } 

    sort(all(elements));

    vector<int> cnt(n, 0);
    int distinct_values = 0;
    int res = INF;
    for (int l = 0, r = 0; r < elements.size(); ++r) {
        auto [val, idx] = elements[r];
        if (cnt[idx] == 0) distinct_values++;
        cnt[idx]++;

        while (distinct_values == n && l < r) {
            res = min(res, val - elements[l].first);
            if (cnt[elements[l].second] == 1) distinct_values--;
            cnt[elements[l].second]--;
            l++;
        }   
    }

    cout << res;

    return 0;
}