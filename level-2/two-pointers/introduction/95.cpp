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

ii find(vector<int> a, int k) {    
    int n = a.size();
    
    int res = 0, idx = -1;
    for (int i = 0, j = 1; j < n; ++j) {
        while (i < j && a[j] - a[i] > k) i++;

        if (j - i + 1 > res) {
            res = j - i + 1;;
            idx = i;
        }
    }

    return {res, idx};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    sort(all(a));

    auto [r1, idx] = find(a, k);
    a.erase(a.begin() + idx, a.begin() + idx + r1);
    auto [r2, _] = find(a, k);
    cout << r1 + r2;

    return 0;
}