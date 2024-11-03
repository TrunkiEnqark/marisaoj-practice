#include <bits/stdc++.h>

using namespace std;

int n, k, total = 0;
vector<int> a;
vector<int> indexed;
vector<int> sums;

bool backtrack(int i) {
    if (i >= n) {
        for (auto sum : sums) {
            if (sum !=  total/k) return false;
        }
        for (int j = 0; j < n; ++j) {
            cout << indexed[j] << ' ';
        }
        return true;
    }

    for (int j = 0; j < k; ++j) {
        if (sums[j] + a[i] > total/k) continue;
        indexed[i] = j + 1;
        sums[j] += a[i];
        bool is_finished = backtrack(i + 1);
        if (is_finished) return true;
        sums[j] -= a[i];
    } 
    return false;
}

int main() {
    cin >> n >> k;
    a.resize(n);

    for (auto& it : a) {
        cin >> it;
        total += it;
    }

    if (total % k != 0) {
        cout << "ze";
        return 0;
    }

    indexed.resize(n);
    sums.resize(k, 0);

    backtrack(0);
}