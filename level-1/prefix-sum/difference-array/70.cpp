#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, m;
    cin >> n >> q >> m;

    vector<int> diff(n + 2, 0), cnt(q + 2, 0);
    vector<pair<int, int>> queries;

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }

    for (int i = 1; i <= q; ++i) 
        cnt[i] += cnt[i - 1];

    for (int i = 0; i < q; ++i) {
        auto [l, r] = queries[i];
        int add = cnt[i + 1];
        diff[l] += add;
        diff[r + 1] -= add;
    }

    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        cout << diff[i] << ' ';
    }
}