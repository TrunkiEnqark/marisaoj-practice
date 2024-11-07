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
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    i32 n;
    cin >> n;

    vec<ii> a(n);
    i32 total = 0;
    for (i32 i = 0; i < n; ++i) cin >> a[i].first;

    for (i32 i = 0; i < n; ++i) {
        cin >> a[i].second;
        total += a[i].second;
    }

    sort(all(a));

    priority_queue<int, vector<int>, greater<int>> pq;
    for (i32 i = 0; i < n; ++i) {
        if (a[i].first > (i32) pq.size()) {
            pq.push(a[i].second);
        } else if (a[i].second > pq.top()) {
            pq.pop();
            pq.push(a[i].second);
        }
    }
    for (; !pq.empty(); pq.pop()) total -= pq.top();
    cout << total;
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