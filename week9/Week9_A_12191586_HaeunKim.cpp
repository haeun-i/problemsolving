#include <iostream>
#include <cmath>
using namespace std;

long long* multiplelist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int x, n, m;
		cin >> x >> n >> m;

		multiplelist = new long long[n + 1];
		multiplelist[1] = x % m;

		long long result = multiplelist[1];

		for (int i = 2; i <= n; i++) {
			multiplelist[i] = multiplelist[i - 1] * x;
			result += multiplelist[i];
		}

		cout << result % m << endl;


	}
	
	delete[] multiplelist;
	return 0;
}