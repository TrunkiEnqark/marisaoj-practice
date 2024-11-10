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

u32 n, m, k;
vec<i32> a, d;
vec<vec<i32>> adj;

void bfs(int i) {
    d.resize(n, INF);
    queue<i32> q;

    d[i] = 0;
    q.push(i);
    while (!q.empty()) {
        i32 u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    a.resize(k);
    adj.resize(n);

    for (auto& it : a) cin >> it, it--;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    bfs(n - 1);

    i32 res = 0;
    for (auto i : a) {
        if (d[i] <= d[0]) res++;
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