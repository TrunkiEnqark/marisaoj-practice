#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, queries;
    cin >> n >> queries;
    vector<int> a(n);
    for (auto& it : a) cin >> it;
    vector<int64_t> prefix(n + 1, 0), f_prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
        f_prefix[i + 1] = f_prefix[i] + 1ll * (i + 1) * a[i]; 
    }

    auto query = [&](int l, int r) {
        return (f_prefix[r] - f_prefix[l - 1]) - (1ll * (l - 1) * (prefix[r] - prefix[l - 1]));
    };

    while (queries--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}