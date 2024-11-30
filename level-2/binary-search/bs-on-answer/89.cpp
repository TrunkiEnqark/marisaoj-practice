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

    ll k;
    cin >> k;

    ll length = 1, cnt = 9, start = 1;
    while (k > cnt * length) {
        k -= cnt * length;
        length++;
        cnt *= 10;
        start *= 10;
    }

    ll num = start + (k - 1) / length;
    ll idx = (k - 1) % length;
    cout << to_string(num)[idx];

    return 0;
}