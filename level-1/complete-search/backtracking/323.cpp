#include <bits/stdc++.h>

using namespace std;

int state[21];

void backtrack(int i, int n, int k) {
    if (i > k) {
        for (int j = 1; j <= k; ++j) cout << state[j] << ' ';
        cout << '\n';
        return;
    }
    for (int next = state[i - 1] + 1; next <= n - k + i; ++next) {
        state[i] = next;
        backtrack(i + 1, n, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    state[0] = 0;
    backtrack(1, n, k);
}