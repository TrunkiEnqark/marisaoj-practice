#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m, a[N][N];

long long kanade(vector<long long> a) {
    long long res = LLONG_MIN;
    long long cur = 0;
    for (auto element : a) {
        cur = max(cur + element, element);
        res = max(res, cur);
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    
    long long res = LLONG_MIN;
    for (int left = 1; left <= m; ++left) {
        vector<long long> temp(n, 0);
        for (int right = left; right <= m; ++right) {
            for (int i = 1; i <= n; ++i) 
                temp[i - 1] += a[i][right];
            res = max(res, kanade(temp));
        }
    }
    cout << res;
}