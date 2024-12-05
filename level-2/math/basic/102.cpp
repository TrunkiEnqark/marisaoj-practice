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
const int N = 2e6 + 5;
const int INF = 1e9;

bool is_prime[N + 1];

void sieve(int lim = N) {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= lim; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= lim; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    sieve();
    for (int i = 2; i <= n; ++i)
        if (is_prime[i]) cout << i << ' ';

    return 0;
}