#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LG = 17;

int n, q, a[N];

struct SparseTable {
    int st[LG][N];

    void build(int arr[], int n) {
        for (int i = 1; i <= n; ++i) st[0][i] = i;
        
        for (int j = 1; j < LG; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                int left = st[j - 1][i];
                int right = st[j - 1][i + (1 << (j - 1))];
                st[j][i] = (arr[right] >= arr[left] ? left : right);
            }
        }
    }

    int query(int arr[], int l, int r) {
        int k = __lg(r - l + 1);
        int left = st[k][l];
        int right = st[k][r - (1 << k) + 1];
        return (arr[left] <= arr[right]) ? left : right;
    }
};

SparseTable st;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    st.build(a, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(a, l, r) << '\n';
    }
}