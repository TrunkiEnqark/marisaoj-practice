#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int result = 0;
vector<int> a;
vector<pair<int, int>> cond[8];

bool check() {
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) return false;
        for (auto [j, k] : cond[i]) {
            if (a[i] + a[j] != k) return false;
        }
    }
    return true;
}

bool is_valid(int i) {
    for (auto [j, k] : cond[i]) {
        if (a[j] != -1 && a[i] + a[j] != k) return false;
    }
    return true;
}

void build_array(int i, int n, int m) {
    if (i > n) {
        result += check();
        return;
    } 
    if (a[i] != -1) {
        build_array(i + 1, n, m);
        return;
    }
    result += check();
    for (int x = 1; x <= m; ++x) {
        a[i] = x;
        if (is_valid(i)) build_array(i + 1, n, m);
        a[i] = -1;
    }
}

int main() {
    cin >> n >> m >> q;
    a.resize(n + 1, -1);

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cond[i].push_back({j, k});
    }

    build_array(1, n, m);
    cout << result;
}