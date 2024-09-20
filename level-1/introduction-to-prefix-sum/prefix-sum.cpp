#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, q;
long long a[N];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
}