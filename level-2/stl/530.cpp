#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n;
    cin >> n;
    multiset<int> houses;  
    multiset<int> distances;  
    
    while (n--) {
        int p;
        cin >> p;
        
        if (houses.count(p)) {  
            auto it = houses.find(p);
            
            if (houses.size() > 1) {
                auto next_it = next(it);
                auto prev_it = it;
                if (prev_it != houses.begin() && next_it != houses.end()) {
                    prev_it = prev(it);
                    distances.erase(distances.find(p - *prev_it));
                    distances.erase(distances.find(*next_it - p));
                    distances.insert(*next_it - *prev_it);
                } else if (prev_it != houses.begin()) {
                    prev_it = prev(it);
                    distances.erase(distances.find(p - *prev_it));
                } else if (next_it != houses.end()) {
                    distances.erase(distances.find(*next_it - p));
                }
            }
            houses.erase(it);
        } else { 
            houses.insert(p);
            
            auto it = houses.find(p);
            if (houses.size() > 1) {
                if (it != houses.begin()) {
                    auto prev_it = prev(it);
                    distances.insert(p - *prev_it);
                }
                auto next_it = next(it);
                if (next_it != houses.end()) {
                    distances.insert(*next_it - p);

                    if (it != houses.begin()) {
                        auto prev_it = prev(it);
                        distances.erase(distances.find(*next_it - *prev_it));
                    }
                }
            }
        }

        if (houses.size() < 2) {
            cout << -1 << '\n';
        } else {
            cout << *distances.begin() << '\n';
        }
    }
    return 0;
}