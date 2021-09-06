#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int q = 0; q < t; q++) {
		int n;
		cin >> n;

		vector<int> block;

		for (int w = 0; w < n; w++) {
			int direct;
			cin >> direct;

			if (direct == 1) {
				int num;
				cin >> num;
				block.push_back(num);
				cout << *min_element(block.begin(), block.end()) << " " << *max_element(block.begin(), block.end());

			}
			else if (direct == 2) {
				if (!block.empty()) {
					block.pop_back();
				}
			}
		}

	}
}