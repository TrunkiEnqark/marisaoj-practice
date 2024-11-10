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

i32 n, m;
vec<vec<ii>> adj;
vec<i32> dn, res;

void bfs(i32 i) {
    dn.resize(N, INF);
    queue<i32> q;

    q.push(i);
    dn[i] = 0;

    while (!q.empty()) {
        i32 u = q.front();
        q.pop();

        for (auto [w, v] : adj[u]) {
            if (dn[v] > dn[u] + 1) {
                dn[v] = dn[u] + 1;
                q.push(v);
            }
        }
    }
}

void dfs(i32 i) {
    stack<i32> st;
    st.push(i);

    while (!st.empty()) {
        i32 u = st.top();
        st.pop();

        if (u == n - 1) {
            cout << res.size() << '\n';
            for (auto w : res) cout << w << ' ';
            return;
        }

        for (auto [w, v] : adj[u]) {
            if (dn[u] == dn[v] + 1) {
                res.push_back(w);
                st.push(v);
                break;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(N);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[--u].push_back({w, --v});
        adj[v].push_back({w, u});
    }

    for (int i = 0; i < N; ++i) 
        sort(all(adj[i]));
    
    bfs(n - 1);

    dfs(0);
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