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
const int MAX_TIME = 100;  

int n, m;
vec<vec<i32>> adj;

vec<bitset<MAX_TIME>> get_possible_times(int start) {
    queue<pair<int,int>> q;  
    vec<bitset<MAX_TIME>> times(n);
    
    q.push({start, 0});
    times[start][0] = 1;
    
    while (!q.empty()) {
        auto [u, t] = q.front();
        q.pop();
        
        if (t >= MAX_TIME - 1) continue;
        
        for (int v : adj[u]) {
            if (!times[v][t + 1]) {
                times[v][t + 1] = 1;
                q.push({v, t + 1});
            }
        }
    }
    
    return times;
}

void solve() {
    i32 a, b;
    cin >> n >> m >> a >> b;
    adj.resize(n);
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    
    auto marisa_times = get_possible_times(a - 1);
    auto reimu_times = get_possible_times(b - 1);
    
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int t = 0; t < MAX_TIME; t++) {
            if (marisa_times[i][t] && reimu_times[i][t]) {
                ans = (ans == -1 ? t : min(ans, t));
                break;
            }
        }
    }
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t = 1;
    while(t--) solve();
    return 0;
}