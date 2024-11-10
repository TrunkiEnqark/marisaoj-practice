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

u32 n;
vec<vec<i32>> adj, capacity;

int bfs(int s, int t, vec<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<ii> q;
    q.push({s, INF});

    while (!q.empty()) {
        auto [cur, flow] = q.front();
        q.pop();

        for (auto next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    vec<int> parent(n + 1);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void solve() {
    u32 m, s, t;
    cin >> n >> m >> s >> t;
    adj.resize(n + 1);
    capacity.resize(n + 1, vec<i32>(n + 1, 0));
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        // adj[v].push_back(u);
        capacity[u][v] += c;
    }

    cout << max_flow(s, t);
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