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

const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;
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

map<int, int> factorization(int num) {
    map<int, int> mp;
    while (num > 1) {
        mp[prime[num]]++;
        num /= prime[num];
    }
    return mp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    sieve();

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    map<int, int> freq;
    for (auto num : a) {
        auto mp = factorization(num);
        for (auto [val, cnt] : mp) 
            freq[val] = max(freq[val], cnt);
    }

    ll res = 1;
    for (auto [val, cnt] : freq) {
        // cout << val << ' ' << cnt << '\n';
        res = (res * (ll) powl(val, cnt)) % MOD;
    }
    cout << res;

    return 0;
}