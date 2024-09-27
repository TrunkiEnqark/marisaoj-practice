#include <bits/stdc++.h>

using namespace std;

/*
sum(l, r) / len = k
<=> (a[l] + a[l+1] + ... + a[r - 1] + a[r]) / (r - l + 1) = k
<=> (a[l] + a[l+1] + ... + a[r - 1] + a[r]) = k * (r - l + 1)
<=> (a[l] - k) + (a[l + 1] - k) + ... + (a[r - 1] - k) + (a[r] - k) = 0
*/

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    unordered_map<long long, int> cnt;
    long long res = 0;
    long long cur = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i) {
        cur += (a[i] - k);
        res += cnt[cur];
        cnt[cur]++;
    }
    cout << res;
}