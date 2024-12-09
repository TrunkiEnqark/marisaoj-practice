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

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto& it : v) cin >> it;

    while (q--) {
        int type;
        cin >> type;

        switch (type) {
            case 1: {
                int x;
                cin >> x;
                v.push_back(x);
                break;
            }
            
            case 2: {
                if (v.size()) v.erase(v.end() - 1);
                break;
            }

            case 3: {
                int k;
                cin >> k;
                cout << v[k - 1] << '\n';
                break;
            }
        }
    }

    return 0;
}