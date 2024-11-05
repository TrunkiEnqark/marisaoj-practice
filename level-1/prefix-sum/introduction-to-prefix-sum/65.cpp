#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n + 1), pre(n + 1, 0), mul(n + 1, 0), mul_rev(n + 2, 0), pre_rev(n + 2, 0);

    int t = n/2;    
    for (int i = 1; i <= n; ++i) { 
        cin >> a[i];
        mul[i] = mul[i - 1] + t * a[i];
        pre[i] = pre[i - 1] + a[i];
        t++;
    }

    t = n/2;
    for (int i = n; i >= 1; --i) {
        pre_rev[i] = pre_rev[i + 1] + a[i];
        mul_rev[i] = mul_rev[i + 1] + t * a[i];
        t++;
    }
    
    auto sum = [&] (int l, int r, int alpha) -> int64_t {
        if (l > r) return 0;
        return mul[r] - mul[l - 1] - (alpha + l - 2) * (pre[r] - pre[l - 1]);
    };
    
    auto sum_rev = [&] (int l, int r, int alpha) -> int64_t {
        if (l > r) return 0;
        return mul_rev[l] - mul_rev[r + 1] - (alpha + n - r - 1) * (pre_rev[l] - pre_rev[r + 1]);
    };
    
    // for (int i = 1; i <= n; ++i) cout << pre[i] << ' '; cout << endl;
    // for (int i = 1; i <= n; ++i) cout << mul[i] << ' '; cout << endl;
    // for (int i = 1; i <= n; ++i) cout << pre_rev[i] << ' '; cout << endl;
    // for (int i = 1; i <= n; ++i) cout << mul_rev[i] << ' '; cout << endl;
    // cout << sum(2, 3, n/2) << ' ' << sum_rev(4, 5, n/2) << '\n';

    auto brute_force = [&](int x) -> ll {
        ll total = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == x) continue;
            ll dist = min(abs(x - i), n - abs(x - i));
            total += dist * a[i];
        }
        return total;
    };
    
    ll res = 1e18;
    for (int i = 1; i <= n; ++i) {
        ll formula, part1, part2, part3;
        if (i > n/2) {
            part1 = sum(1, i - n/2 - 1, i - n/2 - n%2);
            part2 = sum_rev(i - n/2, i - 1, n/2);
            part3 = sum(i + 1, n, n/2);
            formula = part1 + part2 + part3;
        } else {
            part1 = sum_rev(1, i - 1, n/2);
            part2 = sum(i + 1, i + n/2, n/2);
            part3 = sum_rev(i + n/2 + 1, n, n/2 - i + 1);
            formula = part1 + part2 + part3;
        }

        res = min(res, formula);
    }
    cout << res;
    return 0;
}