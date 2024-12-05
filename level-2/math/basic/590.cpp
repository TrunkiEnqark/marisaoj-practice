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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    vector<int> gcd(n);
    gcd[0] = a[0];
    for (int i = 1; i < n; ++i)
        gcd[i] = __gcd(gcd[i - 1], a[i]);
    
    int idx = 0;
    for (int i = 0; i < n; ++i) 
        if (gcd[i] < gcd[idx]) 
            idx = i;
    
    a[idx] = gcd[max(0, idx - 1)];
    int res = a[0];
    for (int i = 1; i < n; ++i) 
        res = __gcd(res, a[i]);
    cout << res;

    return 0;
}