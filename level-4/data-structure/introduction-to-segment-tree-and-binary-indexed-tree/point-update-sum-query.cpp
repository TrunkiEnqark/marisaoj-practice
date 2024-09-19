#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct SegmentTree {
    long long seg[4 * N];

    void build(int arr[], int id, int l, int r) {
        if (l == r) {
            seg[id] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, id * 2, l, mid);
        build(arr, id * 2 + 1, mid + 1, r);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }

    // set arr[idx] = val
    void update(int id, int l, int r, int idx, int val) {
        if (l > idx || r < idx) return;

        if (l == r) {
            seg[id] = val;
            return;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, idx, val);
        update(id * 2 + 1, mid + 1, r, idx, val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }

    // sum query for [u, v]
    long long get_sum(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;

        if (u <= l && r <= v) return seg[id];

        int mid = (l + r) / 2;
        return get_sum(id * 2, l, mid, u, v) + get_sum(id * 2 + 1, mid + 1, r, u, v);
    }
};

int q, n, arr[N];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    SegmentTree seg_tree;
    seg_tree.build(arr, 1, 1, n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i, x;
            cin >> i >> x;
            seg_tree.update(1, 1, n, i, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg_tree.get_sum(1, 1, n, l, r) << '\n';
        }
    }
}