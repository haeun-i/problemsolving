#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		vector<pair<int, int>> room;

		int n;
		cin >> n;

		while (n--) {
			int a, b;
			cin >> a >> b;

			if (!room.empty()) {
				sort(room.begin(), room.end());

				vector<int> big_score;
				for (int i = 0; i < room.size(); i++) {
					if (room[i].first >= a) big_score.push_back(room[i].second);
				}

				int min = b;
				if(!big_score.empty()) min = *min_element(big_score.begin(), big_score.end()); // 거리의 최솟값

				if (b <= min) room.push_back(make_pair(a, b));
			}
			else {
				room.push_back(make_pair(a, b));
			}


		}
		
		cout << room.size() << '\n';


	}

}