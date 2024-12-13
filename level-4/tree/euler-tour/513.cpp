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

int n, q, in[N], out[N], timer = 0;
vector<int> adj[N];

void dfs(int u, int par = -1) {
    in[u] = ++timer;
    for (auto v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    out[u] = timer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> q;
    for (int u, v, i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (in[u] >= in[v] && out[u] <= out[v]) {
            cout << "RI\n";
        } else if (in[v] >= in[u] && out[v] <= out[u]) {
            cout << "MA\n";
        } else {
            cout << "SA\n";
        }
    }

    return 0;
}