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
vec<vec<i32>> adj;
vec<i32> color;

bool dfs(int u) {
    for (auto v : adj[u]) {
        if (color[v] == -1) {
            color[v] = color[u] ^ 1;
            if (!dfs(v)) {
                return false;
            }
        } else if (color[v] == color[u]) {
            return false;
        }
    }
    
    return true;
}

void solve() {
    cin >> n >> m;
    adj.resize(n);
    color.resize(n, -1);
    
    while (m--) {
        i32 u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!dfs(i)) {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
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