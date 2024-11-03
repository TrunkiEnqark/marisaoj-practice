#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p, par;

int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}

int main() {
    cin >> n;
    p.resize(n);
    par.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        par[i] = i;
    }
    
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        // for (int x = 0; x < n; ++x) cout << par[x] << ' '; cout << endl;
        res[i] = find(p[i]);
        par[res[i]] = find((res[i] + 1) % n);
    }
    
    for (int i = 0; i < n; ++i)
        cout << res[i] + 1 << ' ';
}