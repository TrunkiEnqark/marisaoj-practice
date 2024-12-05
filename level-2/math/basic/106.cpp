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
const int N = 1e6;
const int INF = 1e9;

ll f[N + 1], divisors[N + 1];

void preprocess() {
    for (int i = 1; i <= N; ++i) 
        for (int j = i; j <= N; j += i)
            divisors[j]++;

    for (int i = 1; i <= N; ++i) {
        f[i] = f[i - 1] + divisors[i];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);
    
    preprocess();
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << '\n';
    }

    return 0;
}