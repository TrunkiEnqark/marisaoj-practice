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

int n;
ll k, a[N];

void backtrack(int i, int en, unordered_map<ll, int>& s, ll cur = 0) {
    if (i > en) {
        s[cur]++;
        return;
    }
    for (int j = 0; j < 2; ++j) {
        backtrack(i + 1, en, s, cur + j * a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    unordered_map<ll, int> s1, s2;
    backtrack(1, n/2, s1);
    backtrack(n/2 + 1, n, s2);

    for (auto [sum1, _] : s1) {
        if (s2.count(k - sum1)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}