#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int result = 0;
bool col[N], diag1[2 * N], diag2[2 * N];

void backtrack(int i, int n) {
    if (i == n) {
        result++;
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (!col[j] && !diag1[i - j + N] && !diag2[i + j]) {
            col[j] = diag1[i - j + N] = diag2[i + j] = true;
            backtrack(i + 1, n);
            col[j] = diag1[i - j + N] = diag2[i + j] = false;   
        }
    }
}

int main() {
    int n;
    cin >> n;

    memset(col, false, sizeof col);
    memset(diag1, false, sizeof diag1);
    memset(diag2, false, sizeof diag2);

    backtrack(0, n);
    cout << result;
}