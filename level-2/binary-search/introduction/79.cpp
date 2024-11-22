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

struct FenwickTree {
    int n;
    vector<int> bit;
    
    FenwickTree(int _n) : n(_n), bit(_n + 1, 0) {}

    void update(int idx) {
        for (; idx <= n; idx += idx & (-idx)) 
            bit[idx]++;
    }

    int get(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & (-idx)) 
            res += bit[idx];
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    
    unordered_map<int, vector<int>> pos;

    for (int x, i = 1; i <= n; ++i) {
        cin >> x;
        pos[x].push_back(i);
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;

        auto left = lower_bound(all(pos[x]), l) - pos[x].begin();
        auto right = upper_bound(all(pos[x]), r) - pos[x].begin() - 1;
        // cout << left << ' ' << right << endl;
        cout << right - left + 1 << '\n';    
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