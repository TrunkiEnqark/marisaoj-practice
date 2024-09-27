#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> maximum_subarray_from(vector<long long> a, int i, int n, int& pos) {
    vector<long long> prefix(n + 1, LLONG_MIN);
    vector<long long> suffix(n + 1, LLONG_MIN);
    
    long long cur = 0;
    for (int k = i; k < n; ++k) {
        cur = max(cur + a[k], a[k]);
        prefix[k + 1] = max(prefix[k], cur);
    } 

    cur = 0;
    for (int k = n - 1; k >= i; --k) {
        cur = max(cur + a[k], a[k]);
        suffix[k] = max(suffix[k + 1], cur);
    }

    long long res = LLONG_MIN;
    long long left = LLONG_MIN, right = LLONG_MIN;
    for (int k = i + 1; k < n; ++k) {
        long long total = prefix[k] + suffix[k];
        // cout << prefix[k] << ' ' << suffix[k] << endl;
        if (total > res) {
            res = total;
            left = prefix[k];
            right = suffix[k];
            pos = k;
        }
    }
    // cout << "-----------\n";
    return {left, right};
}

long long calculate(vector<long long> a, int n) {
    int pos = 0, temp;
    auto [left, _] = maximum_subarray_from(a, 0, n-1, pos);
    auto [middle, right] = maximum_subarray_from(a, pos, n, temp);
    return left + middle + right;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& it : a) cin >> it;

    long long res = calculate(a, n);
    reverse(a.begin(), a.end());
    res = max(res, calculate(a, n));
    cout << res;
}