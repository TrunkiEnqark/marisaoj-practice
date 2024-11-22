#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll LIM = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<ll> nums;
    
    for (int x = 0; x <= 64; ++x) {
        ll p2 = powl(2, x);
        if (p2 > LIM) break;
        
        for (int y = 0; y <= 39; ++y) {
            ll p3 = powl(3, y);
            if (p2 * p3 > LIM) break;
            
            for (int z = 0; z <= 27; ++z) {
                ll p5 = powl(5, z);
                if (p2 * p3 * p5 > LIM) break;
                
                nums.push_back(p2 * p3 * p5);
            }
        }
    }    

    sort(nums.begin(), nums.end());
    // nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int t = 1;
    cin >> t;
    while(t--) {
        ll num;
        cin >> num;
        auto it = lower_bound(nums.begin(), nums.end(), num);
        if (it != nums.end() && *it == num) {
            cout << it - nums.begin() + 1 << '\n'; 
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}