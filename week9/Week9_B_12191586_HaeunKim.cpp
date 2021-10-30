#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		int** game = new int* [n + 1];
		for (int i = 0; i <= n; i++) {
			game[i] = new int[n + 1];
			memset(game[i], 0, sizeof(int) * (n + 1));
		}

		while (q--) {
			int r, c;
			cin >> r >> c;

			if (q % 2 == 1) {
				game[r][c] = 1; // Èæµ¹
			}
			else if (q % 2 == 0) {
				game[r][c] = 2; // ¹éµ¹
			}
		}
	}
}