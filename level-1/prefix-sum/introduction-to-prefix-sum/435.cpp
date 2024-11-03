#include <bits/stdc++.h>

using namespace std;

/*
cnt0/cnt1 = x/y
=> cnt0 * y = cnt1 * x
*/

int main() {
    int x, y;
    string s;
    cin >> x >> y >> s;

    unordered_map<int, int> cnt;
    long long res = 0;
    int cnt0 = 0, cnt1 = 0;
    cnt[0] = 1;
    for (int i = 0; i < s.length(); ++i) {
        cnt0 += (s[i] == '0');
        cnt1 += (s[i] == '1');
        int key = cnt0*y - cnt1*x;
        res += cnt[key];
        cnt[key]++;
    }
    cout << res;
}