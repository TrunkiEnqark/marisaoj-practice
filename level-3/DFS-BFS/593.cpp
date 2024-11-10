#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Query {
    int u, d, c, idx;
    bool operator < (const Query& other) const {
        return d > other.d; 
    }
};

int n, m, q;
int color[N];
vector<int> adj[N];
bitset<N> vst;
pair<int,int> last[N]; 

inline void bfs(const int src, const int d, const int c) {
    vst.reset();
    
    queue<pair<int,int>> q;
    q.push({src, 0});
    
    vst.set(src);

    while (!q.empty()) {
        const auto [u, dist] = q.front();
        q.pop();
        
        int remaining_dist = d - dist;
        if (last[u].second >= remaining_dist) continue;
        
        last[u] = {c, remaining_dist};
        if (color[u] == 0) color[u] = c;

        if (dist == d) continue;

        for (const int& v : adj[u]) {
            if (!vst.test(v)) {
                vst.set(v);
                q.push({v, dist + 1});
            }
        }
    }
}

inline void solve() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = 0;
        last[i] = {0, -1}; 
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> q;
    vector<Query> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i].u >> queries[i].d >> queries[i].c;
        queries[i].idx = i;
    }

    reverse(queries.begin(), queries.end());

    for(const auto& query : queries) {
        bfs(query.u, query.d, query.c);
    }

    for (int i = 1; i <= n; ++i) {
        cout << color[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    return 0;
}