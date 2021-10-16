#include <iostream>
#include <vector>
using namespace std;

struct point {
	int x;
	int y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {

		vector<point> point_list;
		int n, m;
		cin >> n >> m;
		while (n--) {
			point point;
			cin >> point.x >> point.y;
			point_list.push_back(point);
		}
		while (m--) {
			point point;
			cin >> point.x >> point.y;
			point_list.push_back(point);
		}
	}
}