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

int prime[N + 1];

void sieve() {
    for (int i = 1; i <= N; ++i) prime[i] = i;

    for (int i = 2; i * i <= N; ++i)
        if (prime[i] == i) {
            for (int j = i * i; j <= N; j += i)
                prime[j] = i;
        }
}

vector<int> factorization(int n) {
    vector<int> res;
    while (n > 1) {
        res.push_back(prime[n]);
        int p = prime[n];
        while (n % p == 0) {
            n /= p;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);
    sieve();
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        auto v = factorization(n);
        // reverse(all(v));
        sort(all(v));
        for (auto i : v) cout << i << ' '; 
        cout << '\n';
    }

    return 0;
}