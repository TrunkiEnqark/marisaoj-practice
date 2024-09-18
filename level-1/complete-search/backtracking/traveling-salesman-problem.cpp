#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

int n;
bool vst[15];
int result = INT_MAX;
vector<ii> adj[15];

bool check() {
    for (int i = 1; i <= n; ++i)
        if (!vst[i]) return false;
    return true;
}

void dfs(int u, int start, int cost) {
    if (check()) {
        for (auto [v, dist] : adj[u]) {
            if (v == start) {
                result = min(result, cost + dist);
                break;
            }
        }
        return;
    }
    for (auto [v, dist] : adj[u]) {
        if (!vst[v]) {
            vst[v] = true;
            dfs(v, start, cost + dist);
            vst[v] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            adj[i].push_back({j, d});
        }
    }
    for (int i = 1; i <= n; ++i) {
        memset(vst, false, sizeof vst);
        vst[i] = true;
        dfs(i, i, 0);
    }

    cout << result;
    return 0;
}