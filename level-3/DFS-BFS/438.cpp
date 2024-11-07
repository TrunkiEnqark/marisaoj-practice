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

u32 n, m, k;
vec<vec<i32>> adj;
vec<i32> dist;
vec<u32> p;

void bfs(int i) {
    queue<i32> qu;
    vec<bool> vst(n + 1, false);

    qu.push(i);
    vst[i] = true;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u]) {
            if (!vst[v]) {
                vst[v] = true;
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
} 

void solve() {
    cin >> n >> m >> k;
    adj.resize(n + 1);
    dist.resize(n + 1, 0);
    p.resize(k);

    for (auto& it : p) cin >> it;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(n);

    for (auto i : p) {
        cout << dist[i] << ' ';
    }
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