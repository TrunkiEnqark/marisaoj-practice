#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> diff(n + 1, 0);

    while (q--) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    for (int i = 1; i <= n; ++i) { 
        diff[i] += diff[i - 1];
        cout << diff[i] << ' ';
    }
}