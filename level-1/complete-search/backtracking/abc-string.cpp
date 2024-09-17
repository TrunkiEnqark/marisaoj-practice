#include <bits/stdc++.h>

using namespace std;

const char states[] = {'A', 'B', 'C'};

vector<string> results;

void backtrack(int i, int n, char last, string cur) {
    if (i >= n) {
        results.push_back(cur);
        return;
    }
    for (char state : states) {
        if (state == last) continue;
        backtrack(i + 1, n, state, cur + state);
    }
}

int main() {
    int n;
    cin >> n;
    backtrack(0, n, '?', "");
    for (auto result : results) {
        cout << result << '\n';
    }
}