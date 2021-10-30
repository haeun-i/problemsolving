#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int answer, flag;
		vector<int> resourceA;
		vector<int> resourceB;
		vector<pair<int, int>> resourceSum;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			resourceA.push_back(a);
			resourceB.push_back(b);
			resourceSum.push_back(make_pair(a + b, i));
		}
		sort(resourceSum.begin(), resourceSum.end(), greater<>());
		answer = 0;
		flag = 1;

		for (int i = 0; i < n; i++) {
			if (flag) {
				answer += resourceA[(resourceSum[i].second)];
				flag = 0;
			}
			else if (flag == 0) {
				answer -= resourceB[(resourceSum[i].second)];
				flag = 1;
			}
		}

		cout << answer << '\n';
	}
}