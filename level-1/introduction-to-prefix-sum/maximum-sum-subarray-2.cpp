#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& it : a) cin >> it;

    vector<long long> max_sum_left(n + 1, LLONG_MIN), max_sum_right(n + 1, LLONG_MIN);
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        cur = max(cur + a[i], a[i]);
        max_sum_left[i + 1] = max(max_sum_left[i], cur);
    }
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        cur = max(cur + a[i], a[i]);
        max_sum_right[i] = max(max_sum_right[i + 1], cur);
    }
    long long result = LLONG_MIN;
    for (int i = 1; i < n; ++i) {
        result = max(result, max_sum_left[i] + max_sum_right[i]);
    }
    cout << result;
}