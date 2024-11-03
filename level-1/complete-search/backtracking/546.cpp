#include <bits/stdc++.h>

using namespace std;

int state[21];
bool used[21];

void backtrack(int i, int n, int k) {
    if (i > k) {
        for (int j = 1; j <= k; ++j) cout << state[j] << ' ';
        cout << '\n';
        return;
    }
    for (int next = 1; next <= n; ++next) 
        if (!used[next]) {
            state[i] = next;
            used[next] = true;
            backtrack(i + 1, n, k);
            used[next] = false;
        }
}

int main() {
    int n, k;
    cin >> n >> k;
    memset(used, false, sizeof used);
    state[0] = 0;
    backtrack(1, n, k);
}