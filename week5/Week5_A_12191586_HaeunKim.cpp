#include <iostream>
#include <vector>
using namespace std;

int t, n;
int* signal;
int* prefix;

void ComputePrefixFunction() {
	prefix[1] = 0;
	int k = 0;
	for (int i = 2; i <= n; i++) {
		while (k > 0 && signal[i] != signal[k + 1]) {
			k = prefix[k];
		}
		if (signal[i] == signal[k + 1]) k++;
		prefix[i] = k;
	}
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n;

		signal = new int[n + 1];
		prefix = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			signal[i] = num;
		}

		ComputePrefixFunction();

		for (int i = 1; i <= n - prefix[n]; i++) {
			cout << signal[i] << " ";
		}
		cout << "\n";
	}

	delete[] signal;
	delete[] prefix;
}