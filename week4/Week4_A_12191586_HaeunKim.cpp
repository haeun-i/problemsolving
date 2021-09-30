#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


int t, a, b, x, y, g, cost;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        
        g = abs(a - b);
        cost = (g - (b % g)) * x;

        if (min(a, b) >= g) {
            cost = min(cost, ((b % g) * y));
        }

        cout << g << " " << cost << '\n';

    }
}