#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int room[9999];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int start, dest;
		cin >> start >> dest;

		for (int i = start; i <= dest; i++) {
			string s = to_string(i);
			reverse(s.begin(), s.end());
			int num = stoi(s);
			room[i] = 1 + min(min(room[i + 1], room[i - 1]), room[num]);
		}

		cout << room[dest] << '\n';
	}
}