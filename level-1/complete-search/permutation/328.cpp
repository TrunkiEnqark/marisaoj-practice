#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, b;

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        idx.push_back(i);
    }

    long long minimum_time = LLONG_MAX;
    do {
        long long filling = 0, labeling = 0;
        for (auto i : idx) {
            filling += a[i];
            labeling = max(labeling, filling) + b[i];
        }
        minimum_time = min(minimum_time, max(filling, labeling));
    } while (next_permutation(idx.begin(), idx.end()));
    cout << minimum_time;
}