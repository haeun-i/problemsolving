#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct point {
    int x;
    int y;
    double dist;

    bool operator<(const point& p) const {
        if (dist != p.dist) return dist < p.dist;
        else if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;

        priority_queue<point> stores;

        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            point p;
            p.x = x;
            p.y = y;
            p.dist = sqrt(x * x + y * y);
            stores.push(p);
            if (stores.size() > k) stores.pop();
        }

        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            point p;
            p.x = x;
            p.y = y;
            p.dist = sqrt(x * x + y * y);
            stores.push(p);
            stores.pop();
            cout << stores.top().x << " " << stores.top().y << '\n';
        }
    }
}