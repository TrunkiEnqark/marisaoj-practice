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

u32 n, m;
vec<vec<i32>> adj;
vec<bool> vst;
vec<i32> dist;

void bfs(int i) {
    queue<i32> qu;
    qu.push(i);
    dist[i] = 0;
    vst[i] = true;

    while (!qu.empty()) {
        i32 u = qu.front();
        qu.pop();

        for (auto v : adj[u]) {
            if (!vst[v]) {
                qu.push(v);
                dist[v] = dist[u] + 1;
                vst[v] = true;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n);
    vst.resize(n, false);
    dist.resize(n, -1);

    while (m--) {
        u32 u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    bfs(0);

    for (int i = 1; i < n; ++i)
        cout << dist[i] << ' ';
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