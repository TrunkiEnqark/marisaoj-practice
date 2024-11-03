#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& it : a) cin >> it;

    long long max_sum = LLONG_MIN;
    long long cur = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        cur = max(a[i], cur + a[i]);
        max_sum = max(max_sum, cur);
    }
    cout << max_sum;
}