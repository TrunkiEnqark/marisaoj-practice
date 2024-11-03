#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct Edge {
    int node;
    long long weight;

    bool operator > (const Edge& other) const {
        return weight > other.weight;
    }
};

int n, m;
vector<vector<Edge>> adj;

int main() {
    cin >> n >> m;
    adj.resize(n);
    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[--u].push_back({--v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<int> trace(n, -1);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    dist[0] = 0;    
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [u, du] = pq.top();
        pq.pop();

        if (du > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                pq.push({v, dist[v] = dist[u] + w});
                trace[v] = u;
            }
        }
    }

    if (dist[n - 1] == LLONG_MAX) {
        cout << -1;
        return 0;
    }

    cout << dist[n - 1] << '\n';
    vector<int> path;
    for (int i = n - 1; i != -1; i = trace[i]) 
        path.push_back(i + 1);
    reverse(path.begin(), path.end());
    for (auto u : path) cout << u << ' ';
}   