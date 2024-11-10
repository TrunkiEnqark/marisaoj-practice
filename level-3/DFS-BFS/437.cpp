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
vec<vec<i32>> adj;
vec<vec<i32>> dist;

void solve() {
    cin >> n >> m >> k;
    adj.resize(n);
    while (m--) {
        i32 u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    dist.resize(n, vec<i32>(10, INF));

    queue<ii> q;

    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        i32 u = q.front().first; 
        i32 x = q.front().second;
        q.pop();

        for (auto v : adj[u]) {
            if (dist[v][(x + 1) % k] > dist[u][x] + 1) {
                dist[v][(x + 1) % k] = dist[u][x] + 1;
                q.push({v, (x + 1) % k});
            }
        }
    }

    cout << (dist[n - 1][0] == INF ? -1 : dist[n - 1][0] / k);
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