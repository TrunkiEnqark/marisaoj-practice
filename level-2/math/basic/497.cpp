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

vector<int> factorization(int num) {
    vector<int> res;
    while (num > 1) {
        int p = prime[num];
        res.push_back(p);
        while (num % p == 0) num /= p;
    }
    return res;
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

    vector<ii> res(n, {INF, -2});

    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        auto divisors = factorization(a[i]);

        for (auto divisor : divisors) {
            int j = -1;
            if (mp.count(divisor)) {
                j = max(j, mp[divisor]);
            }

            if (j != -1) {
                if (i - j < res[i].first) res[i] = {i - j, j};
                if (i - j < res[j].first) res[j] = {i - j, i};
            }

            mp[divisor] = i;
        }
    }

    for (auto [_, i] : res) 
        cout << i + 1 << ' ';

    return 0;
}