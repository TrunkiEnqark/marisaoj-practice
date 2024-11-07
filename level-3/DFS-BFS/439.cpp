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
vec<i32> p;
vec<ii> edges;
vec<vec<i32>> adj;

vec<i32> bfs(int i) {
    vec<i32> dist(n, -1);
    vec<bool> vst(n, false);

    queue<i32> q;
    q.push(i);
    dist[i] = 0;
    vst[i] = true;

    while (!q.empty()) {
        i32 u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!vst[v]) {
                vst[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

void solve() {
    cin >> n >> m >> k;
    adj.resize(n);
    edges.resize(m);
    p.resize(k);

    for (auto& it : p) {
        cin >> it;
        it--;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {--u, --v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    i32 res = INT_MAX;
    for (auto [u, v] : edges) {
        auto from_u = bfs(u);
        auto from_v = bfs(v);

        i32 cur = 0;
        bool ok = true;
        for (int i : p) {
            int mi = INT_MAX;
            if (from_u[i] != -1) mi = min(mi, from_u[i]);
            if (from_v[i] != -1) mi = min(mi, from_v[i]);

            if (mi == INT_MAX) {
                ok = false;
                break;
            } 
            cur += mi;
        }
        if (ok) res = min(res, cur);
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