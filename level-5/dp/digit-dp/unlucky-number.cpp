#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[20][2][2][2]; // [pos][last_was_1][tight][is_unlucky]

ll calc(string& n, int pos, bool last, bool tight, bool is_unlucky) {
    if (pos == n.size()) 
        return is_unlucky;

    ll& res = dp[pos][last][tight][is_unlucky];
    if (res != -1) 
        return res;

    res = 0;
    int lim = (tight ? n[pos] - '0' : 9);
    
    for (int dig = 0; dig <= lim; ++dig) {     
        res += calc(n, pos + 1, 
                   dig == 1,
                   tight && (dig == lim), 
                   is_unlucky || dig == 4 || (last && dig == 3));
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << calc(n, 0, false, true, false);

    return 0;
}