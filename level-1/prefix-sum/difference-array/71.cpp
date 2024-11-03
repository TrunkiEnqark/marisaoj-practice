#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2, 0), add(n + 2, 0);

    while (q--) {
        int l, r;
        cin >> l >> r;
        a[l] += (1 - l);
        a[r + 1] -= (1 - l);
        add[l]++;
        add[r + 1]--;
    }

    for (int i = 1; i <= n; ++i) {
        add[i] += add[i - 1];
        a[i] += a[i - 1];
        cout << (ll) a[i] + 1ll * i * add[i] << ' ';
    }

    return 0;
}