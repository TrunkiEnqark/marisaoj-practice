#include <bits/stdc++.h>

using namespace std;

int sum_range(const vector<int>& prefix, int l, int r) {
    return prefix[r] - prefix[l - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + a[i];

    int result = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        result = max({result, 
                      sum_range(prefix, 1, i) * -1 + sum_range(prefix, i + 1, n),
                      sum_range(prefix, 1, i) + sum_range(prefix, i + 1, n) * -1});
    }
    cout << result;
}