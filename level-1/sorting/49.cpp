#include <bits/stdc++.h>

#define NAME ""
#define i32 int
#define i64 int64_t
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vec vector
#define all(a) (a.begin(), a.end())

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(10, 0);
    for (auto c : s) cnt[c - '0']++;

    for (int c = 1; c < 10; ++c) 
        if (cnt[c] > 0) {
            cout << c;
            cnt[c]--;
            break;
        }
    
    for (int c = 0; c < 10; ++c) {
        for (int t = 0; t < cnt[c]; ++t)
            cout << c;
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}