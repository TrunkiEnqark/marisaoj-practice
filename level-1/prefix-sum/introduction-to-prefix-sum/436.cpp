#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    unordered_map<long long, int> cnt;
    cnt[0] = 1;
    long long res = 0;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += a[i];
        res += cnt[cur - target];
        cnt[cur]++;
    }
    cout << res;
}