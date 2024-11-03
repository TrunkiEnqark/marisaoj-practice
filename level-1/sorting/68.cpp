#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y, z;

    // Point(int x, int y, int z) : x(x), y(y), z(z) {}

    bool operator < (const Point& other) {
        return (x < other.x 
                || (x == other.x && y < other.y) 
                || (x == other.x && y == other.y && z < other.z));
    }
};

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto& it : points) cin >> it.x >> it.y >> it.z;
    sort(points.begin(), points.end());
    for (auto& it : points) {
        cout << it.x << " " << it.y << " " << it.z << '\n';
    }
}