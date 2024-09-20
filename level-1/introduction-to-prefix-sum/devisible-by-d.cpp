#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, d, a[N];

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    unordered_map<int, int> cnt;
    int cur = 0;

    cnt[0] = 1;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        cur = ((cur + a[i]) % d + d) % d;
        res += cnt[cur];
        cnt[cur]++;        
    }
    cout << res;
}   