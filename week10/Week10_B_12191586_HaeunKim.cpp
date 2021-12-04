#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int* matryoshka;
int* dp;

int main() {
	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		matryoshka = new int[n + 1];
		dp = new int[n + 1];

		for (int i = 1; i <= n; i++) {
			cin >> matryoshka[i];
		}

		int answer = 0;
	
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int j = 1; j <= i - 1; j++) {
				if (matryoshka[j] < matryoshka[i]) dp[i] = max(dp[i], dp[j] + 1);
			}
			answer = max(dp[i], answer);
		}

		cout << answer << endl;
	}
}