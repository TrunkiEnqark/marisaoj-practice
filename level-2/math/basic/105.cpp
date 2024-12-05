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

vector<int> factorization(int num) {
    vector<int> res;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            int cnt = 0;
            while (num % i == 0) {
                cnt++;
                num /= i;
            }

            if (cnt & 1) {
                res.push_back(i);
            }
        }
    }

    if (num > 1) {
        res.push_back(num);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    map<vector<int>, int> mp;
    ll res = 0;
    for (auto num : a) {
        auto v = factorization(num);
        res += mp[v];
        mp[v]++;
    }
    cout << res;

    return 0;
}