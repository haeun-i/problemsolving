#include <iostream>
#include <set>
using namespace std;

int* messenger;
int* answer;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		messenger = new int[m + 1];
		answer = new int[m + 1];

		for (int i = 1; i <= m; i++) {
			cin >> messenger[i];
		}

		set<int> readers;

		for (int i = m; i >= 1; i--) {
			if (readers.find(messenger[i]) == readers.end()) {
				readers.insert(messenger[i]);
			}
			answer[i] = n - readers.size();
		}

		for (int i = 1; i <= m; i++) {
			cout << answer[i] << '\n';
		}

	}
}