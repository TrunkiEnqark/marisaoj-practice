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
const int N = 1e6 + 5;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    vector<int> freq(N, 0);
    int max_val = 0;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        max_val = max(max_val, x);
        freq[x]++;
    }

    for (int g = max_val; g > 0; --g) {
        int cnt = 0;
        for (int mul = g; mul <= max_val; mul += g) 
            cnt += freq[mul];
        
        if (cnt > 1) {
            cout << g;
            return 0;
        }
    }

    return 0;
}