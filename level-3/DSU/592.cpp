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
vec<i32> a;
vec<vec<i32>> b;

i32 prim() {
    // {weight, vertex}
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vec<bool> vst(n + 1, false);
    vec<i32> min_w(n + 1, INF);
    
    i32 total = 0;
    min_w[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vst[u]) continue;
        vst[u] = true;
        total += w;

        for (i32 v = 0; v <= n; ++v) {
            if (!vst[v] && b[u][v] < min_w[v]) {
                min_w[v] = b[u][v];
                pq.push({min_w[v], v});
            }
        }
    }
    return total;
}

void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n + 1, vec<i32>(n + 1));
    
    for (auto& it : a) cin >> it;

    for (i32 i = 0; i < n; ++i) 
        for (i32 j = 0; j < n; ++j) 
            cin >> b[i][j];

    for (int i = 0; i < n; ++i) 
        b[n][i] = b[i][n] = a[i];

    cout << prim();
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