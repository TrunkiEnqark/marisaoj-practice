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
const int N = 31625;
const int INF = 1e9;

vector<int> primes;
int prime[N + 1];

void sieve() {
    for (int i = 1; i <= N; ++i) prime[i] = i;

    for (int i = 2; i <= N; ++i)
        if (prime[i] == i) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                prime[j] = i;
        }
}

ll divisors(int n) {
    ll res = 1;
    for (int i = 0; i < primes.size() && primes[i] <= n && n > 1; ++i) {
        int p = primes[i];

        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                cnt++;
                n /= p;
            }
            res *= (cnt + 1);
        }
    }

    if (n > 1) res *= 2;

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
        cout << divisors(n) << '\n';
    }

    return 0;
}