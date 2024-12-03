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

int find(vector<int> a, vector<int> b, vector<int> c) {
    int res = INF;

    int n = a.size();
    for (int i = 0, j = 0, k = 0; i < n; ++i) {
        while (j < n && b[j] <= a[i]) {
            while (k < n && c[k] <= b[j]) {
                res = min(res, 2 * (a[i] - c[k]));

                k++;    
            }
            j++;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n));
    for (int k = 0; k < 3; ++k) 
        for (int i = 0; i < n; ++i)
            cin >> a[k][i];

    vector<int> idx(3);
    for (int i = 0; i < 3; ++i) {
        idx[i] = i;
        sort(all(a[i]));
    }
    int res = INF;
    do {
        res = min(res, find(a[idx[0]], a[idx[1]], a[idx[2]]));
    } while (next_permutation(all(idx)));

    cout << res;

    return 0;
}