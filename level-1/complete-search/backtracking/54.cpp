#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> w, v;

int main() {
    cin >> n >> s;
    w.resize(n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }

    long long max_v = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum_w = 0;
        long long sum_v = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                sum_w += w[i];
                if (sum_w > s) {
                    sum_v = -1; 
                    break;
                }
                sum_v += v[i];
            }
        }
        max_v = max(max_v, sum_v);
    }   
    cout << max_v;
}