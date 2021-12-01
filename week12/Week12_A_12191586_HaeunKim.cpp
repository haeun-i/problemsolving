#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long triangle[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<long long> find_min;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> triangle[i][j];

				if (j == 1) triangle[i][j] += triangle[i - 1][j];
				else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
				else {
					triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
				}

				if (i == n) find_min.push_back(triangle[i][j]);
			}
		}

		cout << *min_element(find_min.begin(), find_min.end()) << '\n';
	}
	
}