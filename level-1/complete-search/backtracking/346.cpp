#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
vector<long long> a;

bool backtrack(int i, long long target) {
    if (i >= n) {
        return target == 0;
    }
    for (int j = 0; j < 2; ++j) {
        if (target - 1ll * j * a[i] >= 0) {
            bool is_targeted = backtrack(i + 1, target - 1ll * j * a[i]);
            if (is_targeted) return true;
        } 
    }
    return false;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (auto& it : a) cin >> it;
    cout << (backtrack(0, k) ? "YES\n" : "NO\n");
}