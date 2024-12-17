#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INF = -1e18; 

int n;
long long A[N], B[N];
long long dp[N][3][2]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) cin >> B[i];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }

    dp[1][1][0] = A[1];
    dp[1][1][1] = B[1]; 

    for (int i = 2; i <= n; ++i) {
        dp[i][1][0] = max(dp[i-1][1][1], dp[i-1][2][1]) + A[i];
        dp[i][2][0] = dp[i-1][1][0] + A[i];
        
        dp[i][1][1] = max(dp[i-1][1][0], dp[i-1][2][0]) + B[i];
        dp[i][2][1] = dp[i-1][1][1] + B[i];
    }

    long long result = max({dp[n][1][0], dp[n][2][0], dp[n][1][1], dp[n][2][1]});
    cout << result;

    return 0;
}
