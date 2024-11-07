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

int n, m;
vector<vector<int>> adj;
vector<bool> vst;

void dfs(int u, int par) {
    vst[u] = true;
    for (auto v : adj[u]) {
        if (!vst[v]) {
            dfs(v, u);
        }
    }
}

void solve() {    
    cin >> n >> m;
    adj.resize(n);
    vst.resize(n, false);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    i32 res = 0;
    for (int i = 0; i < n; ++i)
        if (!vst[i]) {
            dfs(i, -1);
            res++;
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