#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int cur = 0;
    unordered_map<int, int> cnt;
    
    cnt[0] = 1;
    long long res = 0;
    for (auto ch : s) {
        if (ch == '1') cur++;
        else cur--;

        if (cnt.find(cur) != cnt.end())
            res += cnt[cur];
        cnt[cur]++;
    }
    cout << res;
}