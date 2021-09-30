#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x, y;
	cin >> t;

	while (t--) {

		int x1, x2, x3, x4, y1, y2, y3, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		if (x3 > x4) {
			swap(x3, x4);
			swap(y3, y4);
		}

		if (x1 == x2 && x3 == x4) {
			if (x1 != x3) cout << 1 << '\n';
			else if (x1 == x3) {
				if (y1 > y2) swap(y1, y2);
				if (y3 > y4) swap(y3, y4);
				if (y1 > y4 || y3 > y2) cout << 1 << '\n';
				if (y1 == y4 || y3 == y2) cout << 2 << '\n';
				if ((y1 <= y3 && y4 <= y2) || (y3 <= y1 && y2 <= y4)) cout << 4 << '\n';
				if ((y1 > y3 && y1 < y4 && y4 < y2) || (y3 > y1 && y3 < y2 && y2 < y4))cout << 3 << '\n';
			}	
		}
		else if (y1 == y2 && y3 == y4) {
			if (y1 != y3) cout << 1 << '\n';
			else if (y1 == y3) {
				if (x1 > x4 || x3 > x2) cout << 1 << '\n';
				if (x1 == x4 || x3 == x2) cout << 2 << '\n';
				if ((x1 <= x3 && x4 <= x2) || (x3 <= x1 && x2 <= x4)) cout << 4 << '\n';
				if ((x1 > x3 && x1 < x4 && x4 < x2) || (x3 > x1 && x3 < x2 && x2 < x4))cout << 3 << '\n';
			}
		}
		else if (x1 == x2 && y3 == y4) {
			x = x1;
			y = y3;
			if ((min(y1, y2) <= y && y <= max(y1, y2)) && (x3 <= x && x <= x4)) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
		else if (y1 == y2 && x3 == x4) {
			x = x3;
			y = y1;
			if ((min(y3, y4) <= y && y <= max(y3, y4)) && (x1 <= x && x <= x2)) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
	}

}