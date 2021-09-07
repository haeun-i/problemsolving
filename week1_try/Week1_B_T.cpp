#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int q = 0; q < t; q++) {

		stack<int> min_block;
		stack<int> max_block;

		int n;
		cin >> n;

		for (int w = 0; w < n; w++) {
			int direct;
			cin >> direct;
			
			if (direct == 1) {
				int num;
				cin >> num;
				if (min_block.empty()) {
					min_block.push(num);
					max_block.push(num);
				}
				else {
					min_block.push(min(min_block.top(), num));
					max_block.push(max(max_block.top(), num));
				}

				cout << min_block.top() << " " << max_block.top() << '\n';
			}
			else {
				if (!min_block.empty()) {
					min_block.pop();
					max_block.pop();
				}
			}

		}
	}
}