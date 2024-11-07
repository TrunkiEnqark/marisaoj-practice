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
#define sqr(x) ((double)(1.0*x*x))

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n;
vec<ii> points;
vec<bool> vst;

double dist(ii p1, ii p2) {
    return (double) sqr(abs(p1.fi - p2.fi)) + sqr(abs(p1.se - p2.se));
}

void dfs(int u, double R) {
    vst[u] = true;
    for (int v = 0; v < n; ++v) {
        // if (dist(u, points[i]) > 2*R) return;
        if (!vst[v] && (double) dist(points[u], points[v]) <= (double) R) {
            // cout << dist(points[u], points[v]) << ' ' << R << '\n';
            vst[v] = true;
            dfs(v, R);
        }
    }
}

bool check(double R) {
    fill(vst.begin(), vst.end(), false);
    dfs(0, R);
    
    // cout << fixed << setprecision(6) << R << ' ';
    for (int i = 0; i < n; ++i) {
        // cout << vst[i];
        if (!vst[i]) return false;
    }
    // cout << '\n';

    return true;
}

void solve() {
    cin >> n;
    points.resize(n);
    vst.resize(n);
    for (auto& [x, y] : points) {
        cin >> x >> y;
    }

    // sort(all(points));

    double lo = 0.0, hi = 1e18, res;
    for (int i = 1; i <= 128; ++i) {
        if (lo > hi) break;
        double mid = (lo + hi) / 2.0;
        if (check(4.0 * mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(6) << sqrt(hi);
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