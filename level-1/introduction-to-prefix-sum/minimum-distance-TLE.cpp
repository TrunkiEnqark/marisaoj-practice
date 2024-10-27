#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll res = LLONG_MAX;
    for (int x = 1; x <= n; ++x) {
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            // printf("dis(%d, %d)=%d\n", x, i, min(abs(i - x), n - abs(i - x)));
            sum += min(abs(i - x), n - abs(i - x)) * a[i];
            
            if (sum >= res) break;
        }
        res = min(res, sum);
    }

    cout << res;

    return 0;
}