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

int n, q, timer = 0;
vector<int> st, en, res;
vector<vector<int>> adj;
vector<bool> vst;

void dfs(int u) {
    st[u] = ++timer;
    vst[u] = true;
    for (auto v : adj[u]) {
        if (!vst[v]) dfs(v);
    }
    en[u] = timer;
}

void solve() {
    cin >> n >> q;
    adj.resize(n + 1); 

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    st.resize(n + 1, 0);
    en.resize(n + 1, 0);
    vst.resize(n + 1, false);
    res.resize(n + 2, 0);
    dfs(1);

    while (q--) {
        int i, x;
        cin >> i >> x;
        res[st[i]] += x;
        res[en[i] + 1] -= x;
    }

    for (int i = 1; i <= n; ++i) res[i] += res[i - 1];
    for (int i = 1; i <= n; ++i) {
        cout << res[st[i]] << ' ';
    }        
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