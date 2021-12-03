#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {

		vector<pair<int, int>> rooms;
		int n;
		cin >> n;
	
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			rooms.push_back(make_pair(a, b));
		}
		
		sort(rooms.begin(), rooms.end(), greater<>());

		int answer = 1;
		int dist = rooms[0].second;

		for (int i = 1; i < n; i++) {
			if (rooms[i].second < dist) {
				answer++;
				dist = rooms[i].second;
			}
		}

		cout << answer << '\n';

	}

}